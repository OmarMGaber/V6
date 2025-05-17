// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: SimilarityBase
//  Project: V6
//  Created by Omar on 17/05/2025.
//  Description: 
//

#ifndef V6_CORE_SEARCH_SIMILARITIES_SIMILARITY_INTERFACE_H_
#define V6_CORE_SEARCH_SIMILARITIES_SIMILARITY_INTERFACE_H_

#include "v6_core/models/document.h"
#include "v6_core/models/types.h"
#include "v6_core/search/weights/weight_base.h"
#include <vector>

namespace v6_core {

class SimilarityBase {
 public:
  explicit SimilarityBase(const v6_core::WeightBase &weight_strategy) : weight_strategy_(weight_strategy) {}
  virtual ~SimilarityBase() = default;

  [[nodiscard]] virtual double ComputeSimilarity(const Document &doc1, const Document &doc2) const = 0;

  // Compute similarity for a certain set of terms
  [[nodiscard]] virtual double ComputeSimilarity(const Document &doc1,
                                   const Document &doc2,
                                   const std::vector<v6_core::TermId> &terms) const = 0;

 protected:
  const v6_core::WeightBase &weight_strategy_;
}; // v6_core
}
#endif //V6_CORE_SEARCH_SIMILARITIES_SIMILARITY_INTERFACE_H_
