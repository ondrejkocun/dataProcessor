cmake_minimum_required(VERSION 3.19)

project(data-processor
    VERSION     0.0.1
    DESCRIPTION "Data Processor - subtitle and data processing libraries"
    LANGUAGES   CXX
)

add_subdirectory(external)

add_subdirectory(libdf)


add_subdirectory(libsrt)
add_executable(test_srt main.cpp)

target_link_libraries(test_srt PRIVATE srt)
