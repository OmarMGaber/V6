// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: FileSystemLoader
//  Project: V6
//  Created by Omar on 06/05/2025.
//  Description:  FileSystemLoader is a LoaderInterface implementation for loading files from the local file system.
//

#include "v6_core/loader/file_system_loader.h"
#include "v6_core/loader/logger.h"

namespace v6_core {

auto logger = GetLogger();

FileSystemLoader::FileSystemLoader(const std::string &path) : path_(std::filesystem::absolute(path)) {
  namespace fs = std::filesystem;

  if (path_.empty()) {
    logger->error("Path is empty");
    throw std::invalid_argument("Path is empty");
  }

  if (!fs::is_regular_file(path_) && !fs::is_directory(path_)) {
    logger->error("Path is not a file or directory: {}", path);
    throw std::invalid_argument("Path is not a file or directory");
  }

  if (!fs::exists(path_)) {
    logger->error("Path does not exist: {}", path);
    throw std::invalid_argument("Path does not exist");
  }

  try {
    this->InitializeQueues(path_);
  } catch (const std::exception &e) {
    logger->error("Failed to initialize files queue: {}", e.what());
    throw;
  }
}

bool FileSystemLoader::HasNext() const {
  return !this->files_.empty();
}

v6_core::FileRAII FileSystemLoader::NextFile() {
  if (!this->HasNext()) {
//    logger->error("No more files to load");
    throw std::out_of_range("No more files to load");
  }

  auto path = this->files_.front();
  this->files_.pop();

  return v6_core::FileRAII(path);
}

void FileSystemLoader::InitializeQueues(const std::filesystem::path &path) {
  namespace fs = std::filesystem;
  if (fs::is_regular_file(path)) {
    this->files_.push(path);
    return;
  }

  // TODO: Make it a buffered queue with a limit, and load the rest files with lazy propagation
  for (const auto &entry : fs::directory_iterator(path)) {
    if (fs::is_regular_file(entry.path())) {
      this->files_.push(entry.path());
    } else if (fs::is_directory(entry.path())) {
      this->InitializeQueues(entry.path());
    }
  }

}  // namespace v6_core

}