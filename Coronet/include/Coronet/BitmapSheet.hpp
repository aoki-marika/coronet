#include "Bitmap.hpp"
#include "Tile.hpp"

namespace Coronet
{
    class BitmapSheet : public Bitmap
    {
        private:
            Vector2 tileSize;
            Vector2 tileCount;
            SDL_Texture *texture = nullptr;

        public:
            BitmapSheet(const char* path, int tileWidth, int tileHeight);
            ~BitmapSheet();

            Vector2 GetTileSize();
            SDL_Texture *ToTexture(SDL_Renderer *renderer, Tile tile);
    };
}