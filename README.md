# V6 Text Search Engine

## Overview
V6 is a text search engine that uses the classical vector space model to search for a query in a collection of documents (corpus).
V6 contains 3 main components:
1. **V6 Core**: The core library that implements all needed components and data structures to build the search engine. (Has alot to be added)
2. **V6 Server**: The server that provides the engine through a REST API. (Not Implemented yet.)
3. **V6 Client**: The client that provides a read-evaluate-print loop (REPL) interface to interact with the server. (Not Implemented yet.)

## Installation Requirements 

Before building or running this project, make sure your system has the following requirements:

### 1. C++ Compiler

You need a C++ compiler that supports C++20 or later (the project uses C++20). 

- **Windows**: Install [MinGW-w64](https://www.mingw-w64.org/).
- **Linux**: Most distributions come with GCC pre-installed. You can install it using your package manager:
  - Debian/Ubuntu: `sudo apt install build-essential`
  - Fedora: `sudo dnf install gcc-c++`

### 2. CMake

This project uses [CMake](https://cmake.org/) for build configuration.
  * **Windows**: Install via [Chocolatey](https://chocolatey.org/): `choco install cmake`
  * **Linux**: Use your package manager, e.g. `sudo apt install cmake`

Or you can download from the official website [CMake's website](https://cmake.org/).

## Build and Run
1. Clone the repository
```bash
git clone https://github.com/OmarMGaber/V6
```

2. Build the project
```bash
cd V6
make
```

## License
This project is released under the Apache License 2.0

## Code Style
This project follows the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).

## Note
The project is still in its early stages and is considered a toy project.