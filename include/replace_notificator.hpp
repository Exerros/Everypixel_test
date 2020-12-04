#pragma once

#include <chrono>
#include <filesystem>
#include <ostream>

namespace epx_test {
    using std::ostream;
    using std::filesystem::path;
    using std::chrono::steady_clock;
    using std::chrono::time_point;
    using std::chrono::duration;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;

    constexpr auto
    START_MSG = "Replacement started in file: ",
    FINISH_MSG = "Replacement finished in file: ",
    COUNT_MSG = ". Number of changes is ",
    TIME_MSG = ". Total time of operation ";

    class Notificator {
    private:
        const path& filePath;
        ostream* outputStream;
        decltype(steady_clock::now()) startTime;
    public:
        unsigned long replaceCount;

        Notificator(const path& filePath, ostream* output);
        ~Notificator();
    };
}

