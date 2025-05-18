// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: Tokenizer
//  Project: V6
//  Created by Omar on 17/05/2025.
//  Description: 
//

#ifndef V6_CORE_V6_CORE_TOKENIZER_H_
#define V6_CORE_V6_CORE_TOKENIZER_H_

#include <string>
#include <vector>
#include <unordered_set>
#include <stdexcept>
#include <utility>

namespace v6_core {
  class Tokenizer {
   public:
    explicit Tokenizer(std::unordered_set<char> delimiters);
    ~Tokenizer() = default;

    std::vector<std::string> Tokenize(const std::string &text);
    std::string NextToken();
    bool HasNext() const;
    void Reset(std::string text);

   private:
    std::unordered_set<char> delimiters_;
    std::string str_;
    size_t str_size_{};
    size_t pos_{};

    void adjustPos();
  };
}

#endif //V6_CORE_V6_CORE_TOKENIZER_H_
