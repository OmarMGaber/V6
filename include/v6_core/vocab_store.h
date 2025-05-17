// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: VocabStore
//  Project: V6
//  Created by Omar on 10/05/2025.
//  Description: A wrapper class for `std::unordered_map` to store vocabulary.
//

#ifndef V6_CORE_VOCAB_STORE_H_
#define V6_CORE_VOCAB_STORE_H_

#include <string>
#include <unordered_map>
#include <string>
#include <unordered_map>
#include <cstdint>

namespace v6_core {

class VocabStore {
 private:
    std::unordered_map<std::string, size_t> vocab_ = {}; // term -> term_id
 public:
    VocabStore() = default;

    bool Put(const std::string &term);
    size_t Get(const std::string &term) const;
};

} // v6_core

#endif //V6_CORE_VOCAB_STORE_H_
