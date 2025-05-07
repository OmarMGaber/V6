cmake_minimum_required(VERSION 3.10)
project(V6)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES "src/v6_server/*.cc")
add_executable(V6 ${SOURCES}
        src/v6_core/loader/loader_interface.cc
        include/v6_core/loader/loader_interface.h
        src/v6_core/loader/file_system_loader.cc
        include/v6_core/loader/file_system_loader.h
        src/v6_core/models/document.cc
        include/v6_core/models/document.h
        include/v6_core/loader/logger.h
        src/v6_core/loader/logger.cc
        src/v6_core/parser/parser_interface.cc
        include/v6_core/parser/parser_interface.h
        src/v6_core/parser/text_parser.cc
        include/v6_core/parser/text_parser.h
        src/v6_core/models/parsed_element.cc
        include/v6_core/models/parsed_element.h)

include(FetchContent)
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.11.0
)
FetchContent_MakeAvailable(spdlog)

target_link_libraries(V6 PRIVATE spdlog::spdlog)