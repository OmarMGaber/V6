// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// File: loader_interface.h
// Project: V6
// Created by Omar on 06/05/2025.
// Description: Defines the interface for loaders.

#ifndef V6_CORE_LOADER_INTERFACE_H_
#define V6_CORE_LOADER_INTERFACE_H_

#include <memory>
#include "v6_core/loader/file_raii.h"

namespace v6_core {

// Provides the method to load data, expected to be implemented by derived classes.
class LoaderInterface {
 public:
  virtual ~LoaderInterface() = default;
  [[nodiscard]] virtual bool HasNext() const = 0;

  [[nodiscard]] virtual v6_core::FileRAII NextFile() = 0;
};

}  // namespace v6_core

#endif  // V6_CORE_LOADER_INTERFACE_H_
