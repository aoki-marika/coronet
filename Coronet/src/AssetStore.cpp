#include <sstream>

#include "AssetStore.hpp"
#include "System.hpp"

namespace Coronet
{
    AssetStore::AssetStore()
    {
        PHYSFS_init(System::GetExecutablePath());
    }

    AssetStore::~AssetStore()
    {
        PHYSFS_deinit();
    }

    void AssetStore::throwPhysfsException(std::string message)
    {
        PHYSFS_ErrorCode code = PHYSFS_getLastErrorCode();
        std::stringstream details;
        details << message << ", " << PHYSFS_getErrorByCode(code) << " (" << code << ").";

        throw std::invalid_argument(details.str());
    }

    void AssetStore::Mount(std::string path)
    {
        const char *fullPath = System::PathRelativeToExecutable(path.c_str());

        if (PHYSFS_mount(fullPath, NULL, 1) == 0)
        {
            std::stringstream message;
            message << "Failed to mount archive at '" << fullPath << "'";
            throwPhysfsException(message.str());
        }
    }

    std::shared_ptr<Bitmap> AssetStore::GetBitmap(std::string path)
    {
        return Get<Bitmap>("Images/" + path);
    }

    std::shared_ptr<BitmapSheet> AssetStore::GetBitmapSheet(std::string path, int tileWidth, int tileHeight)
    {
        return Get<BitmapSheet>("Images/" + path, tileWidth, tileHeight);
    }

    std::shared_ptr<TTFFont> AssetStore::GetTTF(std::string path, int ptsize)
    {
        return Get<TTFFont>("Fonts/" + path, ptsize);
    }
}