#include "srt_writer.hpp"
#include "utils.hpp"

namespace srt {

void NativeSrtWriter::writeImpl(
    const df::DataFrame<Subtitles>& df,
    std::ostream& ost)
{
    int i = 1;
    df.apply([&](const Subtitles& s) {
        ost << i++ << "\n";
        ost << utils::msToStr(s.from)
            << " --> "
            << utils::msToStr(s.to) << "\n";
        ost << s.text << "\n";
    });
}

nlohmann::json JSONSrtWriter::toJSON(const Subtitles& s) {
    return {
        {"id", s.id},
        {"from", utils::msToStr(s.from)},
        {"to", utils::msToStr(s.to)},
        {"text", s.text}
    };
}

}
