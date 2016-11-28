cmake_minimum_required(VERSION 3.6)
project(ashop_cplusplus)

include(build/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src/ashop)
add_subdirectory(src/main)
add_subdirectory(test)

enable_testing()
