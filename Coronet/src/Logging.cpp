#include <iostream>
#include <chrono>
#include <iomanip>
#include <mach-o/dyld.h>
#include <libgen.h>

#include "Logging.hpp"

using namespace std::chrono;

namespace Coronet
{
    Logger::Logger(const char *filename)
    {
        // todo: move to a platform specific implementation elsewhere
        char executablePath[PATH_MAX];
        uint32_t size = sizeof(executablePath);
        _NSGetExecutablePath(executablePath, &size);

        char *realPath, *dirName;
        realPath = realpath(executablePath, NULL);
        dirName = dirname(realPath);

        strcat(dirName, "/");
        strcat(dirName, filename);

        logFile.open(dirName, std::fstream::out | std::ofstream::trunc);
    }

    Logger::~Logger()
    {
        logFile.close();
    }

    Logger &Logger::Get()
    {
        static Logger logger = Logger("coronet.log");

        return logger;
    }

    void Logger::Log(std::string text, LogLevel level)
    {
        const char *levelName[] = { "Info", "Warning", "Error", "Debug" };
        LogColour colour = LogColour::Default;

        switch (level)
        {
            case LogLevel::Warning:
                colour = LogColour::Yellow;
                break;
            case LogLevel::Error:
                colour = LogColour::Red;
                break;
            case LogLevel::Debug:
                colour = LogColour::Cyan;
                break;
            default:
                break;
        }

        auto now = system_clock::now();

        auto now_t = system_clock::to_time_t(now);
        auto time = std::put_time(std::localtime(&now_t), "%T");
        auto ms = duration_cast<milliseconds>(now - time_point_cast<seconds>(now));

        std::stringstream line;
        line << "[" << time << "." << std::setw(3) << std::setfill('0') << ms.count() << "]" << // time ([hr:min:sec.ms])
                "[" << levelName[(int)level] << "] " << // level name ([level])
                text;

        std::clog << "\033[1;" << (int)colour << "m" << // colour header
                     line.str() <<
                     "\033[0m" << std::endl; // colour terminator

        logFile << line.str() << std::endl;
    }

    LogStream::LogStream(Logger &logger, LogLevel level) : logger(logger), level(level)
    {
    }

    LogStream::~LogStream()
    {
        logger.Log(str(), level);
    }

    LogStream Log(LogLevel level)
    {
        return Coronet::Logger::Get()(level);
    }
}