add_library(srt STATIC)

target_sources(srt
    PRIVATE
        srt_loader.cpp
        srt_writer.cpp
        utils.cpp
)

target_include_directories(srt
    PUBLIC
        ..
)

target_link_libraries(srt
    PUBLIC
        df
        nlohmann_json::nlohmann_json
)

target_compile_options(srt PRIVATE -Wall -Wextra -Wpedantic)
target_compile_features(srt PUBLIC cxx_std_20)
