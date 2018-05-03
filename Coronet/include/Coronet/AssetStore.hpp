#include <string>
#include <sstream>
#include <physfs.h>

#include "Bitmap.hpp"
#include "BitmapSheet.hpp"
#include "TTFFont.hpp"
#include "Utilities.hpp"

namespace Coronet
{
    class AssetStore
    {
        public:
            AssetStore();
            ~AssetStore();

            void Mount(std::string path);
            std::shared_ptr<Bitmap> GetBitmap(std::string path);
            std::shared_ptr<BitmapSheet> GetBitmapSheet(std::string path, int tileWidth, int tileHeight);
            std::shared_ptr<TTFFont> GetTTF(std::string path, int ptsize);

            template<typename T, typename... Args> std::shared_ptr<T> Get(std::string path, Args&&... args)
            {
                const char *fullPath = ("assets/" + path).c_str();
                PHYSFS_File *file = PHYSFS_openRead(fullPath);

                if (file == nullptr)
                {
                    std::stringstream message;
                    message << "Failed to read file at '" << fullPath << "'";
                    ThrowPHYSFSException("openRead", message.str());
                }

                int length = PHYSFS_fileLength(file);
                char *buffer[length];
                int lengthRead = PHYSFS_readBytes(file, buffer, length);

                if (lengthRead == -1)
                {
                    std::stringstream message;
                    message << "Failed to read file at '" << fullPath << "'";
                    ThrowPHYSFSException("readBytes", message.str());
                }

                PHYSFS_close(file);
                return std::make_shared<T>(SDL_RWFromMem(buffer, length), args...);
            }
    };
}