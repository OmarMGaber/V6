// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: TermProcessor
//  Project: V6
//  Created by Omar on 10/05/2025.
//  Description: Provides a collection of functions to manipulate terms by applying linguistic operations.
//

#ifndef V6_CORE_LINGUISTICS_TERM_PROCESSOR_H_
#define V6_CORE_LINGUISTICS_TERM_PROCESSOR_H_

#include <string>
#include <algorithm>
#include <string>
#include <cctype>

namespace v6_core::linguistics {
inline void ToLower(std::string &term) {
  std::transform(term.begin(), term.end(), term.begin(), ::tolower);
}
// TODO: implement stemmer, lemmatizer, stop word removal, etc...
}
#endif //V6_CORE_LINGUISTICS_TERM_PROCESSOR_H_
