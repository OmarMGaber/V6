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

#include "v6_core/vocab_store.h"

namespace v6_core {
bool VocabStore::Put(const std::string &term) {
  static int64_t id = 0;

  if (vocab_.contains(term)) {
    return false;
  }

  vocab_[term] = id;
  ++id;
  return true;
}

v6_core::TermId VocabStore::Get(const std::string &term) const {
  auto it = vocab_.find(term);
  if (it != vocab_.end()) {
    return it->second;
  }
  return -1;
}
} // v6_core