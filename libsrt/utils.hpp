
#ifndef LIBSRT_UTILS_HPP
#define LIBSRT_UTILS_HPP

#include <chrono>
#include <string>
#include <string_view>

namespace srt::utils {

std::chrono::milliseconds strToMs(std::string_view str);
std::string msToStr(std::chrono::milliseconds ms);

}

#endif
