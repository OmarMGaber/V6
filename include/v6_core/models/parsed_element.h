// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: ParsedElement
//  Project: V6
//  Created by Omar on 07/05/2025.
//  Description: 
//

#ifndef V6_SRC_V6_CORE_MODELS_PARSED_ELEMENT_H_
#define V6_SRC_V6_CORE_MODELS_PARSED_ELEMENT_H_

#include <cstdint>
#include <string>

namespace v6_core {

class ParsedElement {
 private:
  std::string line_;
  int64_t weight_;
  int64_t line_number_;
 public:
  explicit ParsedElement(std::string line, int64_t weight, int64_t line_number);
  [[nodiscard]] inline std::string Line();
  [[nodiscard]] inline int64_t Weight() const;
  [[nodiscard]] inline int64_t LineNumber() const;
};
} // v6_core

#endif //V6_SRC_V6_CORE_MODELS_PARSED_ELEMENT_H_
