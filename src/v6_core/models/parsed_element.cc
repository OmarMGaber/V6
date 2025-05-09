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

#include "v6_core/models/parsed_element.h"

namespace v6_core {

ParsedElement::ParsedElement(std::string line, int64_t weight, int64_t line_number)
    : line_(std::move(line)), weight_(weight), line_number_(line_number) {}

std::string ParsedElement::Line() {
    return line_;
}

int64_t ParsedElement::Weight() const {
  return weight_;
}

int64_t ParsedElement::LineNumber() const {
  return line_number_;
}

} // v6_core