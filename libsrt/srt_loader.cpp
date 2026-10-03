#include "srt_loader.hpp"
#include "utils.hpp"

#include <fstream>
#include <string>

namespace srt {

df::DataFrame<Subtitles> SrtLoader::load(const std::filesystem::path& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open srt file");
    }

    std::vector<Subtitles> result;
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        Subtitles s;
        s.id = std::stoi(line);

        std::getline(file, line);
        auto pos = line.find(" --> ");
        s.from = utils::strToMs(line.substr(0, pos));
        s.to   = utils::strToMs(line.substr(pos + 5));

        s.text.clear();
        while (std::getline(file, line) && !line.empty()) {
            s.text += line + "\n";
        }

        result.push_back(std::move(s));
    }

    return df::DataFrame<Subtitles>(std::move(result));
}

}
