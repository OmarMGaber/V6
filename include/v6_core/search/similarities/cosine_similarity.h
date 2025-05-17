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

#ifndef V6_CORE_SEARCH_SIMILARITIES_COSINE_SIMILARITY_H_
#define V6_CORE_SEARCH_SIMILARITIES_COSINE_SIMILARITY_H_

#include "similarity_base.h"
#include "utils.h"

namespace v6_core {

class CosineSimilarity : public SimilarityBase {
 public:
  explicit CosineSimilarity(const WeightBase &weight_strategy);
  ~CosineSimilarity() override = default;

  [[nodiscard]] double ComputeSimilarity(const Document &doc1, const Document &doc2) const override;

  [[nodiscard]] double ComputeSimilarity(const Document &doc1,
                           const Document &doc2,
                           const std::vector<v6_core::TermId> &terms) const override;

  double ComputeSimilarityNormalized(const Document &doc1,
                                     const Document &doc2,
                                     const std::vector<v6_core::TermId> &terms) const;
};

} // v6_core

#endif //V6_CORE_SEARCH_SIMILARITIES_COSINE_SIMILARITY_H_
