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

#ifndef V6_SRC_V6_CORE_MODELS_DOCUMENT_H_
#define V6_SRC_V6_CORE_MODELS_DOCUMENT_H_

#include <filesystem>
#include <cstdint>
#include <string>

namespace v6_core {

class Document {
 private:
  const int64_t id_;
  const std::string abs_path_;
 public:
  explicit Document(int64_t id, std::string abs_path);

  [[nodiscard]] inline std::string Name();
  [[nodiscard]] inline std::string BasePath();
};

} // v6_core

#endif //V6_SRC_V6_CORE_MODELS_DOCUMENT_H_
