#include <sstream>
#include <iostream>
#include <physfs.h>

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

    AssetFile AssetStore::Read(const char *path)
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
        return AssetFile(buffer, length);
    }
}