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

#include "v6_core/models/query_result.h"

namespace v6_core {
void QueryResult::AddDocument(const Document &doc, double score) {
  results_.emplace_back(doc, score);
}

const std::vector<std::pair<const Document &, double>> &QueryResult::Results() const {
  return results_;
}

size_t QueryResult::Size() const {
  return results_.size();
}

bool QueryResult::Empty() const {
  return results_.empty();
}

std::vector<std::pair<const Document &, double>>::const_iterator QueryResult::begin() const {
  return results_.begin();
}

std::vector<std::pair<const Document &, double>>::const_iterator QueryResult::end() const {
  return results_.end();
}

} // v6_core