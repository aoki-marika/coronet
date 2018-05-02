#include <string>
#include <sstream>
#include <physfs.h>

#include "AssetFile.hpp"
#include "Bitmap.hpp"
#include "BitmapSheet.hpp"
#include "TTFFont.hpp"

namespace Coronet
{
    class AssetStore
    {
        private:
            void throwPhysfsException(std::string message);

        public:
            AssetStore();
            ~AssetStore();

            void Mount(std::string path);
            std::shared_ptr<Bitmap> GetBitmap(std::string path);
            std::shared_ptr<BitmapSheet> GetBitmapSheet(std::string path, int tileWidth, int tileHeight);
            std::shared_ptr<TTFFont> GetTTF(std::string path, int ptsize);

            template<typename T, typename... Args> T Get(std::string path, Args&&... args)
            {
                const char *fullPath = ("assets/" + path).c_str();
                PHYSFS_File *file = PHYSFS_openRead(fullPath);

                if (file == nullptr)
                {
                    std::stringstream message;
                    message << "Failed to read file at '" << fullPath << "'";
                    throwPhysfsException(message.str());
                }

                int length = PHYSFS_fileLength(file);
                char *buffer = new char[length];
                int lengthRead = PHYSFS_readBytes(file, buffer, length);

                if (lengthRead == -1)
                {
                    std::stringstream message;
                    message << "Failed to read file at '" << fullPath << "'";
                    throwPhysfsException(message.str());
                }

                PHYSFS_close(file);
                return { buffer, length, args... };
            }
    };
}