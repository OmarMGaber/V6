// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: WeightInterface
//  Project: V6
//  Created by Omar on 17/05/2025.
//  Description: 
//

#ifndef V6_CORE_SEARCH_WEIGHTS_WEIGHT_INTERFACE_H_
#define V6_CORE_SEARCH_WEIGHTS_WEIGHT_INTERFACE_H_

#include "v6_core/models/document.h"

class WeightInterface {
 public:
  virtual ~WeightInterface() = default;

  [[nodiscard]] virtual double ComputeWeight(const v6_core::TermId &id, const v6_core::Document &doc) const = 0;
};

#endif //V6_CORE_SEARCH_WEIGHTS_WEIGHT_INTERFACE_H_
