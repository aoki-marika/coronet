#include <sstream>
#include <fstream>

namespace Coronet
{
    enum class LogColour
    {
        Black = 30,
        Red = 31,
        Green = 32,
        Yellow = 33,
        Blue = 34,
        Magenta = 35,
        Cyan = 36,
        White = 37,
        Default = 39
    };

    enum class LogLevel
    {
        Info,
        Warning,
        Error,
        Debug
    };

    class Logger;

    class LogStream : public std::ostringstream
    {
        private:
            Logger &logger;
            LogLevel level;

        public:
            LogStream(Logger &log, LogLevel level);
            ~LogStream();
    };

    class Logger
    {
        private:
            std::fstream logFile;

        public:
            Logger(const char *filename); //relative to folder containing the binary
            ~Logger();

            static Logger &Get();
            void Log(std::string text, LogLevel level);

            LogStream operator()(LogLevel level)
            {
                return LogStream(*this, level);
            }
    };

    LogStream Log(LogLevel level);
}