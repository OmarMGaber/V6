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

#ifndef V6_CORE_PARSER_TEXT_PARSER_H_
#define V6_CORE_PARSER_TEXT_PARSER_H_

#include "parser_interface.h"
#include <sstream>
#include "v6_core/linguistics/term_processor.h"

namespace v6_core {

class TextParser : public v6_core::ParserInterface {
 public:
    explicit TextParser(std::istream &in_stream);

    std::vector<std::string> ParseNext() override;

    bool HasNext() override;
};

}

#endif //V6_CORE_PARSER_TEXT_PARSER_H_
