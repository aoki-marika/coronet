#include "AssetFile.hpp"

namespace Coronet
{
    AssetFile::AssetFile(char *buffer, int length)
    {
        this->buffer = buffer;
        rw = SDL_RWFromMem(buffer, length);
    }

    AssetFile::~AssetFile()
    {
        SDL_RWclose(rw);
        delete buffer;
    }

    SDL_RWops *AssetFile::GetRWops()
    {
        return rw;
    }
}