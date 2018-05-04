#include "System.hpp"

#ifdef __APPLE__
#include <mach-o/dyld.h>
#include <iomanip>
#include <libgen.h>
#endif

namespace Coronet
{
    char *System::GetExecutablePath()
    {
        #ifdef __APPLE__
            char executablePath[PATH_MAX];
            uint32_t size = sizeof(executablePath);
            _NSGetExecutablePath(executablePath, &size);

            return realpath(executablePath, NULL);
        #else
            // todo: these are temporary until support for linux/windows is added
            throw std::system_error("Unsupported OS.");
        #endif
    }

    char *System::GetExecutableDirectory()
    {
        #ifdef __APPLE__
            char *executablePath = GetExecutablePath();
            return dirname(executablePath);
        #else
            throw std::system_error("Unsupported OS.");
        #endif
    }

    const char *System::GetPathSeparator()
    {
        #ifdef WIN32
            return "\\";
        #else
            return "/";
        #endif
    }

    const char *System::PathRelativeToExecutable(const char *path)
    {
        char *newPath = GetExecutableDirectory();
        strcat(newPath, GetPathSeparator());
        strcat(newPath, path);

        return newPath;
    }
}