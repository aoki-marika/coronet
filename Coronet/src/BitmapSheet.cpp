#include <sstream>
#include <SDL2/SDL_image.h>

#include "BitmapSheet.hpp"

namespace Coronet
{
    BitmapSheet::BitmapSheet(const char *path, int tileWidth, int tileHeight) : Bitmap(path)
    {
        tileSize = { tileWidth, tileHeight };
        tileCount = { GetSurface()->w / tileWidth, GetSurface()->h / tileHeight };
    }

    BitmapSheet::BitmapSheet(SDL_Surface *surface, int tileWidth, int tileHeight) : Bitmap(surface)
    {
        tileSize = { tileWidth, tileHeight };
        tileCount = { surface->w / tileWidth, surface->h / tileHeight };
    }

    BitmapSheet::BitmapSheet(SDL_RWops *rw, int tileWidth, int tileHeight) : BitmapSheet(IMG_Load_RW(rw, 0), tileWidth, tileHeight)
    {
        this->rw = rw;
    }

    BitmapSheet::~BitmapSheet()
    {
        if (rw != nullptr)
            SDL_RWclose(rw);
    }

    Vector2 BitmapSheet::GetTileSize()
    {
        return tileSize;
    }

    Vector2 BitmapSheet::GetTileCount()
    {
        return tileCount;
    }

    std::shared_ptr<Bitmap> BitmapSheet::GetTile(Tile tile)
    {
        if (tile.GetSheetPosition().x >= tileCount.x || tile.GetSheetPosition().y >= tileCount.y)
        {
            std::stringstream message;
            message << "Tile at (" << tile.GetSheetPosition().x << "," << tile.GetSheetPosition().y << ") is out of bounds of sheet with size (" << tileCount.x << "," << tileCount.y << ").";
            throw std::invalid_argument(message.str());
        }

        SDL_PixelFormat *format = GetSurface()->format;
        SDL_Surface *surface = SDL_CreateRGBSurface(0,
                                                    tileSize.x,
                                                    tileSize.y,
                                                    format->BitsPerPixel,
                                                    format->Rmask,
                                                    format->Gmask,
                                                    format->Bmask,
                                                    format->Amask);

        if (format->palette != nullptr)
            SDL_SetSurfacePalette(surface, format->palette);

        SDL_Rect sourceRect = {
            tileSize.x * tile.GetSheetPosition().x,
            tileSize.y * tile.GetSheetPosition().y,
            tileSize.x,
            tileSize.y
        };

        auto key = GetColourKey();
        bool colourKeyed = IsColourKeyed();

        // fill the background with the keyed colour so the background of the bitmap is blank
        if (colourKeyed)
            SDL_FillRect(surface, NULL, key);

        SDL_BlitSurface(GetSurface(), &sourceRect, surface, NULL);
        auto bitmap = std::make_shared<Bitmap>(surface);

        if (colourKeyed)
            bitmap->SetColourKey(key);

        return bitmap;
    }
}