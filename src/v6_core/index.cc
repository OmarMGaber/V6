// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: Index
//  Project: V6
//  Created by Omar on 14/05/2025.
//  Description: Index class for managing documents and their terms and providing query functionality.
//

#include "v6_core/index.h"

namespace v6_core {

void Index::AddDocuments(LoaderInterface &loader) {
  if (!loader.HasNext()) {
    return;
  }

  while (loader.HasNext()) {
    auto file = loader.NextFile();
    std::ifstream &stream = file.Stream();

    if (!stream.is_open()) {
      std::cerr << "Failed to open file: " << file.Path() << std::endl;
      continue;
    }

    documents_.push_back(std::make_unique<Document>(DocumentId(documents_.size()), file.Path()));

    auto &doc = *documents_.back();

    TextParser parser(stream);
    while (parser.HasNext()) {
      auto tokens = parser.ParseNext();
      for (auto &token : tokens) {
        store_.Put(token);
        auto term_id = store_.Get(token);
        doc.AddTerm(term_id, 1);
        inverted_index_[term_id].insert(doc.Id());
      }
    }
  }
}

v6_core::QueryResult Index::Query(const std::string &query) {
  v6_core::Document query_doc(0, "");

  std::unordered_map<int, double> query_tfidf;
  std::vector<TermId> tokens;
  auto stream = std::istringstream(query);
  TextParser par(stream);

  while (par.HasNext()) {
    for (const auto &word : par.ParseNext()) {
      TermId term_id = store_.Get(word);
      if (term_id == -1) {
        continue;
      }
      tokens.push_back(term_id);
      query_doc.AddTerm(term_id, 1);
    }
  }

  // Keep them here for now to test
  std::unordered_map<DocumentId, double> dot_products;
  auto w = v6_core::TF_IDF_Weight(inverted_index_, documents_.size());
  v6_core::CosineSimilarity csim(w);

  for (const auto &term : tokens) {
    for (const auto &doc_id : inverted_index_[term]) {
      if (dot_products.contains(doc_id)) {
        continue;
      }
      dot_products[doc_id] = csim.ComputeSimilarity(query_doc, *documents_[doc_id], tokens);
    }
  }

  // TODO: handle sorting in QueryResult
  std::vector<std::pair<DocumentId, double>> ranked;
  for (const auto &[doc_id, score] : dot_products) {
    ranked.emplace_back(doc_id, score);
  }
  std::sort(ranked.begin(), ranked.end(), [](const auto &a, const auto &b) {
    return a.second > b.second;
  });

  v6_core::QueryResult res;
  for (const auto &[doc_id, score] : ranked) {
    res.AddDocument(*documents_[doc_id], score);
  }
  return res;
}

Index::Index(v6_core::VocabStore &store) : store_(store) {}

} // namespace v6_core