#include <sstream>

#include "BitmapSheet.hpp"

namespace Coronet
{
    BitmapSheet::BitmapSheet(const char *path, int tileWidth, int tileHeight) : Bitmap(path)
    {
        tileSize = { tileWidth, tileHeight };
    }

    BitmapSheet::~BitmapSheet()
    {
        if (texture != nullptr)
            SDL_DestroyTexture(texture);
    }

    Vector2 BitmapSheet::GetTileSize()
    {
        return tileSize;
    }

    SDL_Texture *BitmapSheet::ToTexture(SDL_Renderer *renderer, Tile tile)
    {
        // SDL_CreateTextureFromSurface is expensive, so only call it once and cache the result
        if (texture == nullptr)
        {
            texture = Bitmap::ToTexture(renderer);

            int w, h;
            SDL_QueryTexture(texture, NULL, NULL, &w, &h);
            tileCount = { w / tileSize.x, h / tileSize.y };
        }

        if (tile.GetSheetPosition().x >= tileCount.x || tile.GetSheetPosition().y >= tileCount.y)
        {
            std::stringstream message;
            message << "Tile at (" << tile.GetSheetPosition().x << "," << tile.GetSheetPosition().y << ") is out of bounds of sheet with size (" << tileCount.x << "," << tileCount.y << ").";
            throw std::invalid_argument(message.str());
        }

        SDL_Texture *tileTexture = SDL_CreateTexture(renderer,
                                                     SDL_PIXELFORMAT_RGBA8888,
                                                     SDL_TEXTUREACCESS_TARGET,
                                                     tileSize.x,
                                                     tileSize.y);

        SDL_Rect sourceRect = {
            tileSize.x * tile.GetSheetPosition().x,
            tileSize.y * tile.GetSheetPosition().y,
            tileSize.x,
            tileSize.y
        };

        SDL_SetRenderTarget(renderer, tileTexture);
        SDL_RenderCopy(renderer, texture, &sourceRect, NULL);
        SDL_SetRenderTarget(renderer, NULL);

        return tileTexture;
    }
}