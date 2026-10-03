#include <libsrt/srt_loader.hpp>
#include <libsrt/srt_processor.hpp>
#include <libsrt/srt_writer.hpp>

#include <chrono>

int main(int argc, char **argv) {
    srt::SrtLoader loader;
    srt::NativeSrtWriter nativeWriter;
    srt::JSONSrtWriter jsonWriter;

    srt::SrtProcessor processor;
    processor.load(loader, argv[1]);
    processor.write(nativeWriter, "native.srt");
    processor.offset(std::chrono::seconds{2});
    processor.write(jsonWriter, "json.json");
}
