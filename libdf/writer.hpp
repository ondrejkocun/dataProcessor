#ifndef LIBDF_WRITER_HPP
#define LIBDF_WRITER_HPP

#include <fstream>
#include <stdexcept>
#include <filesystem>

namespace df {

template<typename T>
class Writer {
public:
    virtual ~Writer() = default;

    void write(const T& df, const std::filesystem::path& path) {
        std::ofstream ost(path);
        if (!ost.is_open()) {
            throw std::runtime_error("Cannot open file for writing: " + path.string());
        }
        writeImpl(df, ost);
    }

protected:
    virtual void writeImpl(const T& df, std::ostream& ost) = 0;
};

} // namespace df

#endif
