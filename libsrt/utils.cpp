#include "utils.hpp"
#include <iomanip>
#include <sstream>

namespace srt::utils {

std::chrono::milliseconds strToMs(std::string_view str) {
    int h, m, s, ms;
    char c1, c2, c3;

    std::stringstream ss{std::string(str)};
    ss >> h >> c1 >> m >> c2 >> s >> c3 >> ms;

    return std::chrono::milliseconds{
        ((h * 60 + m) * 60 + s) * 1000 + ms
    };
}


std::string msToStr(std::chrono::milliseconds ms) {
    auto total = ms.count();

    int h = total / 3600000;
    total %= 3600000;
    int m = total / 60000;
    total %= 60000;
    int s = total / 1000;
    int ms_part = total % 1000;

    std::ostringstream os;
    os << std::setw(2) << std::setfill('0') << h << ":"
       << std::setw(2) << std::setfill('0') << m << ":"
       << std::setw(2) << std::setfill('0') << s << ","
       << std::setw(3) << std::setfill('0') << ms_part;

    return os.str();
}

}
