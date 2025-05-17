// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: FileRAII
//  Project: V6
//  Created by Omar on 16/05/2025.
//  Description: RAII wrapper for file handling between the loader and the index.
//

#ifndef V6_CORE_LOADER_FILE_RAII_H_
#define V6_CORE_LOADER_FILE_RAII_H_

#include <fstream>
#include <string>
#include <memory>
#include <filesystem>

namespace v6_core {

class FileRAII {
 public:
  explicit FileRAII(const std::filesystem::path &path);
  [[nodiscard]] std::ifstream &Stream();
  [[nodiscard]] std::string Path() const;
  [[nodiscard]] std::string Filename() const;
  ~FileRAII();


 private:
  std::unique_ptr<std::ifstream> stream_;
  std::filesystem::path path_;
};

} // v6_core

#endif //V6_CORE_LOADER_FILE_RAII_H_
