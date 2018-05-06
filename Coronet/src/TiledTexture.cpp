#include <sstream>

#include "TiledTexture.hpp"
#include "Renderer.hpp"

namespace Coronet
{
    // todo: allow setting areas to different palettes
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

        if (sheet->IsColourKeyed())
            SDL_SetTextureBlendMode(tilesTexture, SDL_BLENDMODE_BLEND);
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

    // todo: allow setting tiles before loading
    void TiledTexture::SetTile(int x, int y, Tile tile)
    {
        if (x < 0 || y < 0 || x >= size.x || y >= size.y)
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

        auto tileBitmap = sheet->GetTile(tile);

        for (auto &p : palettes)
        {
            auto a = p.first;

            if (x >= a.x && y >= a.y &&
                x < a.x + a.w && y < a.y + a.h)
                tileBitmap->SetPalette(p.second);
        }

        SDL_Texture *texture = tileBitmap->ToTexture(renderer);

        SDL_SetRenderTarget(renderer, tilesTexture);
        SDL_RenderCopy(renderer, texture, NULL, &destRect);
        SDL_SetRenderTarget(renderer, NULL);
    }

    void TiledTexture::SetPalette(Palette palette)
    {
        SetPalette({ 0, 0, size.x, size.y }, palette);
    }

    // todo: add a redraw area function so the palette can be updated realtime
    void TiledTexture::SetPalette(SDL_Rect area, Palette palette)
    {
        if (area.x < 0 || area.y < 0 || area.x + area.w > size.x || area.y + area.y > size.y)
        {
            std::stringstream message;
            message << "Rect (" << area.x << "," << area.y << "," << area.w << "," << area.h << ") is out of bounds of tiled texture with size (" << size.x << "," << size.y << ").";
            throw std::invalid_argument(message.str());
        }

        palettes.push_back(std::make_pair(area, palette));
    }
}
