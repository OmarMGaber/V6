// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: tokenizer
//  Project: V6
//  Created by Omar on 17/05/2025.
//  Description: 
//

#include "v6_core/tokenizer.h"

namespace v6_core {

Tokenizer::Tokenizer(std::unordered_set<char> delimiters) : delimiters_(std::move(delimiters)), pos_(0) {}

std::string Tokenizer::NextToken() {
  if (!this->HasNext()) {
    throw std::out_of_range("No more tokens available");
  }

  size_t end = pos_;
  while (end < str_size_ && !delimiters_.contains(str_[end])) {
    ++end; // instead of shrink_to_fit
  }

  std::string token = str_.substr(pos_, end - pos_);
  pos_ = end;

  this->adjustPos();
  return token;
}

std::vector<std::string> Tokenizer::Tokenize(const std::string &text) {
  std::vector<std::string> tokens;

  this->Reset(text);
  while (this->HasNext()) {
    tokens.push_back(this->NextToken());
  }

  return tokens;
}

bool Tokenizer::HasNext() const {
  return pos_ < str_size_;
}

void Tokenizer::Reset(std::string text) {
  str_ = std::move(text);
  str_size_ = str_.size();
  pos_ = 0;

  adjustPos();
}
void Tokenizer::adjustPos() {
  while (pos_ < str_size_ && delimiters_.contains(str_[pos_])) {
    ++pos_;
  }
}

} // v6_core