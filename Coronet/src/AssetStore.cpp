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

    void AssetStore::Mount(const char *path)
    {
        const char *fullPath = System::PathRelativeToExecutable(path);

        if (PHYSFS_mount(fullPath, NULL, 1) == 0)
        {
            std::stringstream message;
            message << "Failed to mount archive at '" << fullPath << "'";
            throwPhysfsException(message.str());
        }
    }
}