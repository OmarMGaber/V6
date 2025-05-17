// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: FileRAII
//  Project: V6
//  Created by Omar on 12/05/2025.
//  Description: RAII wrapper for file handling between the loader and the index.
//

#include "v6_core/loader/file_raii.h"

namespace v6_core {

FileRAII::FileRAII(const std::filesystem::path &path)
    : path_(path), stream_(std::make_unique<std::ifstream>(path)) {
  if (!stream_->is_open()) {
    throw std::runtime_error("Failed to open file: " + path.string());
  }
}

[[nodiscard]] std::ifstream &FileRAII::Stream() {
  return *stream_;
}

std::string FileRAII::Filename() const {
  return path_.filename().string();
}

std::string FileRAII::Path() const {
  return path_.string();
}

FileRAII::~FileRAII() {
  if (stream_ && stream_->is_open()) {
    stream_->close();
  }
}

} // v6_core