#ifndef LIBSRT_SUBTITLES_HPP
#define LIBSRT_SUBTITLES_HPP

#include <string>
#include <chrono>

namespace srt {

struct Subtitles {
    int id;
    std::chrono::milliseconds from;
    std::chrono::milliseconds to;
    std::string text;
};

} // namespace srt

#endif
