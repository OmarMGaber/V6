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

#ifndef V6_CORE_V6_CORE_INDEX_H_
#define V6_CORE_V6_CORE_INDEX_H_

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "v6_core/loader/loader_interface.h"
#include "v6_core/models/types.h"
#include "vocab_store.h"
#include "v6_core/parser/text_parser.h"
#include "v6_core/loader/file_raii.h"
#include "v6_core/models/document.h"
#include "v6_core/search/similarities/cosine_similarity.h"
#include "v6_core/search/weights/tf_idf_weight.h"
#include "v6_core/models/query_result.h"

namespace v6_core {

class Index {
 public:
  explicit Index(
      v6_core::VocabStore &store
//      v6_core::IndexReader &reader, // add this kids later.
//      v6_core::IndexWriter &writer
      ); // TODO: Later, pass a writer and reader for disk storage manipulation.

  void AddDocuments(LoaderInterface &loader);
  v6_core::QueryResult Query(const std::string& query);
  ~Index() = default;

 private:
  v6_core::VocabStore &store_;
  std::vector<std::unique_ptr<v6_core::Document>> documents_; // Borrow the doc object to other objexts (NO OWNERSHIP)
  std::unordered_map<TermId, std::set<DocumentId>> inverted_index_; // term_id -> posting list (doc_ids)

//  void LoadIndex(); // uses the reader
//  void SaveIndex(); // uses the writer
};

} // v6_core

#endif //V6_CORE_V6_CORE_INDEX_H_
