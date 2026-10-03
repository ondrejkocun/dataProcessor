#ifndef LIBDF_JSON_WRITER_HPP
#define LIBDF_JSON_WRITER_HPP

#include "writer.hpp"
#include <nlohmann/json.hpp>

namespace df {

template<typename T>
class JSONWriter : public Writer<T> {
protected:
    void writeImpl(const T& df, std::ostream& ost) override {
        nlohmann::json root = nlohmann::json::array();

        df.apply([&](const auto& record) {
            root.push_back(toJSON(record));
        });

        ost << root.dump(4);
    }

    virtual nlohmann::json toJSON(const typename T::value_type& value) = 0;
};

} // namespace df

#endif
