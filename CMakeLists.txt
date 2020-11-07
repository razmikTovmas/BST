cmake_minimum_required(VERSION 3.8)
project(bst VERSION 1.0.0 LANGUAGES CXX)
option(console_BUILD_TESTS OFF)
option(EXAMPLES "Build Examples" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(src)
add_subdirectory(src)

if (EXAMPLES)
  add_subdirectory(examples)
endif()



