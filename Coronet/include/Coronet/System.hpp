#pragma once

namespace Coronet
{
    class System
    {
        public:
            static char *GetExecutablePath();
            static char *GetExecutableDirectory();
            static const char *GetPathSeparator();
            static const char *PathRelativeToExecutable(const char *path);
    };
}