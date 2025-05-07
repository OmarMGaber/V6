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

#ifndef V6_SRC_LOADER_FILE_SYSTEM_LOADER_H_
#define V6_SRC_LOADER_FILE_SYSTEM_LOADER_H_

#include "loader_interface.h"
#include <string>
#include <queue>
#include <filesystem>
#include <fstream>
#include <memory>

namespace v6_core {

class FileSystemLoader : public LoaderInterface {
 private:
  std::string path_;
  std::queue<std::filesystem::path> file_queue_;
 public:
  explicit FileSystemLoader(std::string path);
  std::vector<std::istream *> Load() override;

  ~FileSystemLoader() override = default;
};

}  // namespace v6_core

#endif  // V6_SRC_LOADER_FILE_SYSTEM_LOADER_H_
