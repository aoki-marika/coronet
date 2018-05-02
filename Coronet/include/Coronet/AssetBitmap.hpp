#include <SDL2/SDL_image.h>

#include "AssetFile.hpp"
#include "Bitmap.hpp"

namespace Coronet
{
    class AssetBitmap : public AssetFile<Bitmap>
    {
        protected:
            std::shared_ptr<Bitmap> CreateAsset() override
            {
                return std::make_shared<Bitmap>(IMG_Load_RW(GetRWops(), 0));
            }

        public:
            AssetBitmap(char *buffer, int length) : AssetFile(buffer, length)
            {
            }
    };
}