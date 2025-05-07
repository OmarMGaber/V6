// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  File: logger
//  Project: V6
//  Created by Omar on 07/05/2025.
//  Description: 
//

#ifndef V6_INCLUDE_V6_CORE_LOADER_LOGGER_H_
#define V6_INCLUDE_V6_CORE_LOADER_LOGGER_H_

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

std::shared_ptr<spdlog::logger>& GetLogger();


#endif //V6_INCLUDE_V6_CORE_LOADER_LOGGER_H_
