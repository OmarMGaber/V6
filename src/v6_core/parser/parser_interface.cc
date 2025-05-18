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

#include "v6_core/parser/parser_interface.h"

namespace v6_core {
ParserInterface::ParserInterface(std::istream &in_stream)
    : in_stream_(in_stream), tokenizer_({' ', '\n', '\t', '\r', '.', ',', ';', ':', '!', '?', '-', '_'}) {
 
  tokenizer_.Reset("");
}
} // v6_core