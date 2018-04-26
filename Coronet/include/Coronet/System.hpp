namespace Coronet
{
    class System
    {
        public:
            static char *GetExecutablePath();
            static char *GetExecutableDirectory();
            static const char *GetPathSeparator();
    };
}