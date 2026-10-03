#ifndef LIBSRT_SRT_PROCESSOR_HPP
#define LIBSRT_SRT_PROCESSOR_HPP

#include <filesystem>
#include <vector>

#include <libdf/data_frame.hpp>
#include "subtitles.hpp"

namespace srt {

class SrtProcessor {
public:
    SrtProcessor()
        : m_subtitles(std::vector<Subtitles>{})
    {}

    template<typename Loader>
    void load(Loader& loader, const std::filesystem::path& path) {
        m_subtitles = loader.load(path);
    }

    template<typename Writer>
    void write(Writer& writer, const std::filesystem::path& path) {
        writer.write(m_subtitles, path);
    }

    template<typename Duration>
    void offset(Duration d) {
        m_subtitles.transform([&](Subtitles& s) {
            s.from += d;
            s.to += d;
        });
    }

private:
    df::DataFrame<Subtitles> m_subtitles;
};

} // namespace srt

#endif
