// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: WeightBase
//  Project: V6
//  Created by Omar on 17/05/2025.
//  Description: 
//

#ifndef V6_CORE_SEARCH_WEIGHTS_WEIGHT_BASE_H_
#define V6_CORE_SEARCH_WEIGHTS_WEIGHT_BASE_H_

#include "weight_interface.h"
#include "v6_core/vocab_store.h"
#include "v6_core/models/types.h"
#include <unordered_map>
#include <set>

namespace v6_core {

class WeightBase : public WeightInterface {
 public:
  explicit WeightBase(const std::unordered_map<TermId, std::set<DocumentId>> &inverted_index) : inverted_index_(inverted_index) {}
  ~WeightBase() override = default;

 protected:
  const std::unordered_map<TermId, std::set<DocumentId>>& inverted_index_;
};

} // v6_core

#endif //V6_CORE_SEARCH_WEIGHTS_WEIGHT_BASE_H_
