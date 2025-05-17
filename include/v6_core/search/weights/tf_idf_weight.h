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

#ifndef V6_CORE_SEARCH_WEIGHTS_TF_IDF_WEIGHT_H_
#define V6_CORE_SEARCH_WEIGHTS_TF_IDF_WEIGHT_H_

#include "weight_base.h"
#include <cmath>

namespace v6_core {

class TF_IDF_Weight : public WeightBase {
 public:
  explicit TF_IDF_Weight(const std::unordered_map<TermId, std::set<DocumentId>> &inverted_index,
                         const size_t &doc_count);
  ~TF_IDF_Weight() override = default;
  [[nodiscard]] double ComputeWeight(const v6_core::TermId &id, const v6_core::Document &doc) const override;
 private:
  double doc_count_;
};

} // v6_core

#endif //V6_CORE_SEARCH_WEIGHTS_TF_IDF_WEIGHT_H_
