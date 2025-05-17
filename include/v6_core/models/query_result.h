// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: QueryResult
//  Project: V6
//  Created by Omar on 17/05/2025.
//  Description: 
//

#ifndef V6_CORE_MODELS_QUERY_RESULT_H_
#define V6_CORE_MODELS_QUERY_RESULT_H_

#include "v6_core/models/document.h"
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>

namespace v6_core {

class QueryResult {
 public:
  QueryResult() = default;
  ~QueryResult() = default;

  void AddDocument(const Document &doc, double score);

  [[nodiscard]] const std::vector<std::pair<const Document &, double>> &Results() const;

  [[nodiscard]] size_t Size() const;

  [[nodiscard]] bool Empty() const;

  [[nodiscard]] std::vector<std::pair<const Document &, double>>::const_iterator begin() const;

  [[nodiscard]] std::vector<std::pair<const Document &, double>>::const_iterator end() const;

 private:
  std::vector<std::pair<const Document &, double>> results_;
};

} // v6_core

#endif //V6_CORE_MODELS_QUERY_RESULT_H_
