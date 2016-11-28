set(MAIN_SOURCE_FILES main.cpp)
add_executable(ashop_cplusplus_main ${MAIN_SOURCE_FILES})
target_link_libraries(ashop_cplusplus_main ashop_cplusplus ${CONAN_LIBS})
