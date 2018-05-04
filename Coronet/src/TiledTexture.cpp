#include <sstream>

#include "TiledTexture.hpp"
#include "Renderer.hpp"

namespace Coronet
{
    TiledTexture::TiledTexture(const std::shared_ptr<BitmapSheet> &sheet, int width, int height)
    {
        this->sheet = sheet;
        this->size = { width, height };
        this->tileSize = sheet->GetTileSize(); // just cache it so we dont have to type out the whole thing everytime

        tiles = std::vector<std::vector<Tile>>(height, std::vector<Tile>(width));
    }

    TiledTexture::~TiledTexture()
    {
        if (tilesTexture != nullptr)
            SDL_DestroyTexture(tilesTexture);
    }

    void TiledTexture::Load(DependencyManager &dependencies)
    {
        Texture::Load(dependencies);

        renderer = dependencies.Get<Renderer>()->GetRenderer();

        tilesTexture = SDL_CreateTexture(renderer,
                                         SDL_PIXELFORMAT_RGBA8888,
                                         SDL_TEXTUREACCESS_TARGET,
                                         size.x * tileSize.x,
                                         size.y * tileSize.y);

        // clear the texture so we dont get graphical issues when not filling all the tiles
        SDL_SetRenderTarget(renderer, tilesTexture);
        SDL_RenderClear(renderer);
        SDL_SetRenderTarget(renderer, NULL);
    }

    SDL_Texture *TiledTexture::GetDrawTexture()
    {
        return tilesTexture;
    }

    Vector2 TiledTexture::GetDrawSize()
    {
        return
        {
            size.x * tileSize.x,
            size.y * tileSize.y
        };
    }

    void TiledTexture::SetTile(int x, int y, Tile tile)
    {
        if (x >= size.x || y >= size.y)
        {
            std::stringstream message;
            message << "Tile position (" << tile.GetSheetPosition().x << "," << tile.GetSheetPosition().y << ") is out of bounds of tiled texture with size (" << size.x << "," << size.y << ").";
            throw std::invalid_argument(message.str());
        }

        tiles[y][x] = tile;

        SDL_Rect destRect =
        {
            x * tileSize.x,
            y * tileSize.y,
            tileSize.x,
            tileSize.y
        };

        SDL_Texture *texture = sheet->GetTile(tile)->ToTexture(renderer);

        SDL_SetRenderTarget(renderer, tilesTexture);
        SDL_RenderCopy(renderer, texture, NULL, &destRect);
        SDL_SetRenderTarget(renderer, NULL);
    }
}
