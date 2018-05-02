#include <string>
#include <physfs.h>

#include "AssetFile.hpp"

namespace Coronet
{
    class AssetStore
    {
        private:
            void throwPhysfsException(std::string message);

        public:
            AssetStore();
            ~AssetStore();

            void Mount(const char *path);

            template<typename T, typename... Args> T Read(const char *path, Args&&... args)
            {
                PHYSFS_File *file = PHYSFS_openRead(path);

                if (file == nullptr)
                {
                    std::stringstream message;
                    message << "Failed to read file at '" << path << "'";
                    throwPhysfsException(message.str());
                }

                int length = PHYSFS_fileLength(file);
                char *buffer = new char[length];
                int lengthRead = PHYSFS_readBytes(file, buffer, length);

                if (lengthRead == -1)
                {
                    std::stringstream message;
                    message << "Failed to read file at '" << path << "'";
                    throwPhysfsException(message.str());
                }

                PHYSFS_close(file);
                return { buffer, length, args... };
            }
    };
}