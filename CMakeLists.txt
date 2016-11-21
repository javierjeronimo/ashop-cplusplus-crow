cmake_minimum_required(VERSION 3.6)
project(ashop_cplusplus)

include(build/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(ashop_cplusplus ${SOURCE_FILES})
target_link_libraries(ashop_cplusplus ${CONAN_LIBS})
