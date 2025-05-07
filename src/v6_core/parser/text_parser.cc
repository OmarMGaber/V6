// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: TextParser
//  Project: V6
//  Created by Omar on 07/05/2025.
//  Description: 
//

#include "../../../include/v6_core/parser/text_parser.h"

namespace v6_core {
TextParser::TextParser(std::istream &in_stream) : ParserInterface(in_stream) {}

std::vector<v6_core::ParsedElement> TextParser::Parse() {
  std::vector<v6_core::ParsedElement> elements;
  std::string line;
  int64_t line_number = 0;

  while (std::getline(in_stream_, line)) {
    if (!line.empty()) {
      elements.emplace_back(line, 1, line_number++);
    }
  }

  elements.shrink_to_fit();
  return elements;
}



} // v6_core