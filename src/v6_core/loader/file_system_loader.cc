// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: FileSystemLoader
//  Project: V6
//  Created by Omar on 06/05/2025.
//  Description:
//
#include <filesystem>
#include <iostream>
#include "../../../include/v6_core/loader/file_system_loader.h"
#include "../../../include/v6_core/loader/logger.h"

namespace v6_core {

auto logger = GetLogger();

FileSystemLoader::FileSystemLoader(std::string path)
    : path_(std::move(path)) {}

std::vector<std::istream *> FileSystemLoader::Load() {
  namespace fs = std::filesystem;

  std::vector<std::istream *> streams;

  fs::path abs_path = fs::absolute(path_);
  logger->info("Loading files from path: {}", abs_path.string());

  if (fs::is_regular_file(abs_path)) {
    auto *stream = new std::ifstream(abs_path);
    if (!stream->is_open()) {
      delete stream;
      logger->error("Failed to open file: {}", abs_path.string());
      throw std::runtime_error("Failed to open file: " + abs_path.string());
    }
    streams.push_back(stream);
  } else if (fs::is_directory(abs_path)) {
    for (const auto &entry : fs::directory_iterator(abs_path)) {
      if (entry.is_regular_file()) {
        auto *stream = new std::ifstream(entry.path());
        if (!stream->is_open()) {
          delete stream;
            logger->error("Failed to open file: {}", entry.path().string());
          throw std::runtime_error("Failed to open file: " + entry.path().string());
        }
        streams.push_back(stream);
      }
    }
  } else {
    logger->error("Invalid path: {}", abs_path.string());
    throw std::runtime_error("Invalid path: " + abs_path.string());
  }

  if (streams.empty()) {
    logger->error("No files found in path: {}", abs_path.string());
    throw std::runtime_error("No files found in path: " + abs_path.string());
  }

    logger->info("Loaded {} files from path: {}", streams.size(), abs_path.string());
  return streams;
}

}  // namespace v6_core
