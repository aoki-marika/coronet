#include <SDL2/SDL_image.h>

#include "AssetBitmap.hpp"

namespace Coronet
{
    AssetBitmap::AssetBitmap(char *buffer, int length) : AssetFile(buffer, length)
    {
    }

    std::shared_ptr<Bitmap> AssetBitmap::CreateAsset()
    {
        return std::make_shared<Bitmap>(IMG_Load_RW(GetRWops(), 0));
    }
}