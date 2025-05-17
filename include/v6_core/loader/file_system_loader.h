// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: FileSystemLoader
//  Project: V6
//  Created by Omar on 06/05/2025.
//  Description: FileSystemLoader is a LoaderInterface implementation for loading files from the local file system.
//

#ifndef V6_CORE_LOADER_FILE_SYSTEM_LOADER_H_
#define V6_CORE_LOADER_FILE_SYSTEM_LOADER_H_

#include "loader_interface.h"
#include <string>
#include <queue>
#include <filesystem>
#include <fstream>

namespace v6_core {

class FileSystemLoader : public LoaderInterface {
 public:
  explicit FileSystemLoader(const std::string &path);
  [[nodiscard]] v6_core::FileRAII NextFile() override;
  bool HasNext() const override;

  ~FileSystemLoader() override = default;
 private:
//  std::queue<std::filesystem::directory_iterator> dirs_;
  std::queue<std::filesystem::path> files_;
  std::filesystem::path path_;
  void InitializeQueues(const std::filesystem::path& path);
};

}  // namespace v6_core

#endif  // V6_CORE_LOADER_FILE_SYSTEM_LOADER_H_
