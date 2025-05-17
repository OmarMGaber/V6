// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: utils
//  Project: V6
//  Created by Omar on 17/05/2025.
//  Description: 
//

#ifndef V6_CORE_SEARCH_SIMILARITIES_UTILS_H_
#define V6_CORE_SEARCH_SIMILARITIES_UTILS_H_

#include <cmath>
#include <vector>


namespace v6_core::utils {
inline double dot_product(const std::vector<double> &vec1, const std::vector<double> &vec2) {
  double result = 0.0;
  for (size_t i = 0; i < vec1.size(); ++i) {
    result += vec1[i] * vec2[i];
  }
  return result;
}

inline double magnitude(const std::vector<double> &vec) {
  double sum = 0.0;
  for (const auto &val : vec) {
    sum += val * val;
  }
  return std::sqrt(sum);
}
}


#endif //V6_CORE_SEARCH_SIMILARITIES_UTILS_H_
