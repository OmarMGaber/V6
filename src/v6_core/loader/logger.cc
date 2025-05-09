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

#include "v6_core/loader/logger.h"

std::shared_ptr<spdlog::logger> logger = spdlog::basic_logger_mt("loader", "logs/loader.log");

std::shared_ptr<spdlog::logger>& GetLogger() {
  return logger;
}
