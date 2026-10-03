#ifndef LIBDF_JSON_LOADER_HPP
#define LIBDF_JSON_LOADER_HPP

#include "loader.hpp"
#include <nlohmann/json.hpp>
#include <fstream>

namespace df {

template <typename T>
class JSONLoader : public Loader<T> {
public:
    JSONLoader() = default;

    DataFrame<T> load(const std::filesystem::path& path) override;

    virtual T createData(const nlohmann::json& object) = 0;
};


template <typename T>
DataFrame<T> JSONLoader<T>::load(const std::filesystem::path& path)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open JSON file: " + path.string());
    }

    nlohmann::json j;
    file >> j;

    
    std::vector<T> result;
    result.reserve(j.size());
    for (const auto& element : j) {
        result.push_back(this->createData(element));
    }

    return DataFrame<T>(std::move(result));
}

} // namespace df

#endif
