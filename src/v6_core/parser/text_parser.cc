// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: TextParser
//  Project: V6
//  Created by Omar on 07/05/2025.
//  Description: Parser definition for text files.
//

#include "v6_core/parser/text_parser.h"

namespace v6_core {
TextParser::TextParser(std::istream &in_stream) : ParserInterface(in_stream) {}

std::vector<std::string> TextParser::ParseNext() {
  std::string line;
  std::getline(in_stream_, line);

  std::vector<std::string> tokens;
  std::string token;

  this->tokenizer_.Reset(line);

  while (this->tokenizer_.HasNext()) {
//    v6_core::ProcessTerm(token);
    token = this->tokenizer_.NextToken();
    if (token.empty()) {
      continue;
    }

    tokens.push_back(token);
  }

  return tokens;
}

bool TextParser::HasNext() {
  return !in_stream_.eof();
}

} // v6_core