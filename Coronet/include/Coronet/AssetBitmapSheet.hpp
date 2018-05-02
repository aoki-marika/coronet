#include <SDL2/SDL_image.h>

#include "AssetFile.hpp"
#include "BitmapSheet.hpp"

namespace Coronet
{
    class AssetBitmapSheet : public AssetFile<BitmapSheet>
    {
        private:
            Vector2 tileSize;

        protected:
            std::shared_ptr<BitmapSheet> CreateAsset() override
            {
                return std::make_shared<BitmapSheet>(IMG_Load_RW(GetRWops(), 0), tileSize.x, tileSize.y);
            }

        public:
            AssetBitmapSheet(char *buffer, int length, int tileWidth, int tileHeight) : AssetFile(buffer, length)
            {
                tileSize = { tileWidth, tileHeight };
            }
    };
}