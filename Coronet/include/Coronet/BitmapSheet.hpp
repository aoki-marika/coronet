#pragma once

#include "Bitmap.hpp"
#include "Tile.hpp"

namespace Coronet
{
    class BitmapSheet : public Bitmap
    {
        private:
            Vector2 tileSize;
            Vector2 tileCount;
            SDL_RWops *rw = nullptr;

        public:
            BitmapSheet(const char *path, int tileWidth, int tileHeight);
            BitmapSheet(SDL_Surface *surface, int tileWidth, int tileHeight);
            BitmapSheet(SDL_RWops *rw, int tileWidth, int tileHeight);
            ~BitmapSheet();

            Vector2 GetTileSize();
            Vector2 GetTileCount();
            std::shared_ptr<Bitmap> GetTile(Tile tile);
    };
}