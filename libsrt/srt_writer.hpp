#ifndef LIBSRT_SRT_WRITER_HPP
#define LIBSRT_SRT_WRITER_HPP

#include <libdf/writer.hpp>
#include <libdf/json_writer.hpp>
#include <libdf/data_frame.hpp>

#include "subtitles.hpp"

namespace srt {

class NativeSrtWriter : public df::Writer<df::DataFrame<Subtitles>> {
protected:
    void writeImpl(const df::DataFrame<Subtitles>& df, std::ostream& ost) override;
};

class JSONSrtWriter : public df::JSONWriter<df::DataFrame<Subtitles>> {
protected:
    nlohmann::json toJSON(const Subtitles& s) override;
};

}

#endif
