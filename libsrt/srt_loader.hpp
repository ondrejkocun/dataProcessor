#ifndef LIBSRT_SRT_LOADER_HPP
#define LIBSRT_SRT_LOADER_HPP

#include <libdf/loader.hpp>
#include "subtitles.hpp"

namespace srt {

class SrtLoader : public df::Loader<Subtitles> {
public:
    df::DataFrame<Subtitles> load(const std::filesystem::path& path) override;
};

}

#endif
