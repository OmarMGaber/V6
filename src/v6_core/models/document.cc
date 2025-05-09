// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: document
//  Project: V6
//  Created by Omar on 06/05/2025.
//  Description: 
//

#include "v6_core/models/document.h"

namespace fs = std::filesystem;

namespace v6_core {

Document::Document(int64_t id, std::string abs_path)
    : id_(id), abs_path_(std::move(abs_path)) {}

std::string Document::Name() {
  return fs::path(abs_path_).filename().string();
}

std::string Document::BasePath() {
  return fs::path(abs_path_).parent_path().string();
}

} // v6_core