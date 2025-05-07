// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: ParserInterface
//  Project: V6
//  Created by Omar on 07/05/2025.
//  Description: 
//

#ifndef V6_SRC_V6_CORE_PARSER_PARSER_INTERFACE_H_
#define V6_SRC_V6_CORE_PARSER_PARSER_INTERFACE_H_

#include <istream>
#include <string>
#include <vector>
#include "../models/parsed_element.h"

namespace v6_core {

class ParserInterface {
 protected:
  std::istream &in_stream_;
 public:
  explicit ParserInterface(std::istream &in_stream);

  virtual ~ParserInterface() = default;

  virtual std::vector<v6_core::ParsedElement> Parse() = 0;
  virtual v6_core::ParsedElement ParseNext() = 0;
  virtual bool hasNext() = 0;
};

} // v6_core

#endif //V6_SRC_V6_CORE_PARSER_PARSER_INTERFACE_H_
