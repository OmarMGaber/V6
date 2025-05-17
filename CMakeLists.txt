cmake_minimum_required(VERSION 3.10)
project(V6 LANGUAGES CXX)

# Set C++ standard and policies
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Project structure variables
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_THIRD_PARTY_DIR ${PROJECT_SOURCE_DIR}/third_party)

#-------------------------------------------------------------------------------
# Dependencies
#-------------------------------------------------------------------------------

# Eigen (header-only)
add_library(Eigen3 INTERFACE IMPORTED)
target_include_directories(Eigen3 INTERFACE
        ${PROJECT_THIRD_PARTY_DIR}/eigen
)

# spdlog
include(FetchContent)
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.11.0
)
FetchContent_MakeAvailable(spdlog)

#-------------------------------------------------------------------------------
# Source Files
#-------------------------------------------------------------------------------

# Core source files
set(CORE_SOURCES
        src/v6_core/models/document.cc
        src/v6_core/models/term.cc
        src/v6_core/models/query_result.cc

        src/v6_core/loader/file_system_loader.cc
        src/v6_core/loader/logger.cc
        src/v6_core/loader/file_raii.cc

#        src/v6_core/linguistics/term_processor.cc

        src/v6_core/parser/text_parser.cc
        src/v6_core/parser/parser_interface.cc

        src/v6_core/vocab_store.cc
        src/v6_core/index.cc
        src/v6_core/tokenizer.cc

        src/v6_core/search/similarities/cosine_similarity.cc
        src/v6_core/search/weights/tf_idf_weight.cc

#        Header files

        include/v6_core/loader/loader_interface.h
        include/v6_core/loader/file_system_loader.h
        include/v6_core/loader/logger.h
        include/v6_core/loader/file_raii.h

        include/v6_core/models/document.h
        include/v6_core/models/term.h
        include/v6_core/models/types.h

        include/v6_core/parser/parser_interface.h
        include/v6_core/parser/text_parser.h
        include/v6_core/linguistics/term_processor.h

        include/v6_core/vocab_store.h
        include/v6_core/index.h
        include/v6_core/tokenizer.h

        include/v6_core/search/similarities/cosine_similarity.h
        include/v6_core/search/similarities/similarity_base.h

        include/v6_core/search/weights/weight_interface.h
        include/v6_core/search/weights/weight_base.h
        include/v6_core/search/weights/tf_idf_weight.h
        include/v6_core/search/similarities/utils.h
        include/v6_core/models/query_result.h
)

# Server source files
file(GLOB APP_SOURCES "src/v6_app/*.cc")

#-------------------------------------------------------------------------------
# Executable Target
#-------------------------------------------------------------------------------

add_executable(V6
        ${APP_SOURCES}
        ${CORE_SOURCES}
)

# Add the include directory for Snowball
include_directories(${PROJECT_THIRD_PARTY_DIR}/snowball/include)


#-------------------------------------------------------------------------------
# Target Properties
#-------------------------------------------------------------------------------

target_include_directories(V6 PRIVATE
        ${PROJECT_INCLUDE_DIR}
)

target_link_libraries(V6 PRIVATE
        spdlog::spdlog
        Eigen3
)

#-------------------------------------------------------------------------------
# Installation (optional)
#-------------------------------------------------------------------------------

install(TARGETS V6
        RUNTIME DESTINATION bin
)