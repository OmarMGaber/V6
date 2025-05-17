// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: TF_IDF_Weight
//  Project: V6
//  Created by Omar on 17/05/2025.
//  Description: 
//

#include "v6_core/search/weights/tf_idf_weight.h"

namespace v6_core {
TF_IDF_Weight::TF_IDF_Weight(const std::unordered_map<TermId, std::set<DocumentId>> &inverted_index,
                             const size_t &doc_count) : WeightBase(inverted_index), doc_count_((double)doc_count) {}

double TF_IDF_Weight::ComputeWeight(const v6_core::TermId &term_id, const v6_core::Document &doc) const {
  // TF * log(DC / (1 + DF)) === TF * IDF
  return doc.TF(term_id) * log(doc_count_ / (double) (1 + inverted_index_.at(term_id).size()));
}
} // v6_core