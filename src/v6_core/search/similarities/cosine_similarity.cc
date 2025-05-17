// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: CosineSimilarity
//  Project: V6
//  Created by Omar on 17/05/2025.
//  Description:
//

#include "v6_core/search/similarities/cosine_similarity.h"

namespace v6_core {
CosineSimilarity::CosineSimilarity(const WeightBase &weight_strategy)
    : SimilarityBase(weight_strategy) {}

// Use it for single documents and not for queries
double CosineSimilarity::ComputeSimilarity(const Document &doc1, const Document &doc2) const {
  std::set<TermId> terms;
  for (const auto &[term, _] : doc1.Terms()) {
    terms.insert(term);
  }

  for (const auto &[term, _] : doc2.Terms()) {
      terms.insert(term);
  }

  return ComputeSimilarity(doc1, doc2, std::vector<TermId>(terms.begin(), terms.end()));
}

// Use it in queries, terms are query document terms
double CosineSimilarity::ComputeSimilarity(const Document &doc1,
                                           const Document &doc2,
                                           const std::vector<v6_core::TermId> &terms) const {
  std::vector<double> vec1(terms.size(), 0.0);
  std::vector<double> vec2(terms.size(), 0.0);

  for (size_t i = 0; i < terms.size(); ++i) {
    vec1[i] = weight_strategy_.ComputeWeight(terms[i], doc1);
    vec2[i] = weight_strategy_.ComputeWeight(terms[i], doc2);
  }

  return v6_core::utils::dot_product(vec1, vec2); // / (v6_core::utils::magnitude(vec1) * v6_core::utils::magnitude(vec2));
}

double CosineSimilarity::ComputeSimilarityNormalized(const Document &doc1,
                                           const Document &doc2,
                                           const std::vector<v6_core::TermId> &terms) const {
  std::vector<double> vec1(terms.size(), 0.0);
  std::vector<double> vec2(terms.size(), 0.0);

  for (size_t i = 0; i < terms.size(); ++i) {
    vec1[i] = weight_strategy_.ComputeWeight(terms[i], doc1);
    vec2[i] = weight_strategy_.ComputeWeight(terms[i], doc2);
  }

  return v6_core::utils::dot_product(vec1, vec2) / (v6_core::utils::magnitude(vec1) * v6_core::utils::magnitude(vec2));
}

} // v6_core