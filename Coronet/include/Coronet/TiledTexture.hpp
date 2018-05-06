#pragma once

#include <vector>
#include <SDL2/SDL.h>

#include "Texture.hpp"
#include "Tile.hpp"
#include "Vector2.hpp"
#include "BitmapSheet.hpp"

namespace Coronet
{
    // todo: iffy on the name, as its not the standard naming scheme for texture subclasses
    // todo: TiledTexture -> TiledSprite
    class TiledTexture : public Texture
    {
        private:
            std::shared_ptr<BitmapSheet> sheet;
            std::vector<std::pair<SDL_Rect, Palette>> palettes;
            Vector2 size; // in tiles
            Vector2 tileSize;
            std::vector<std::vector<Tile>> tiles;
            SDL_Texture *tilesTexture = nullptr;
            SDL_Renderer *renderer;

        protected:
            Vector2 GetDrawSize() override;
            SDL_Texture *GetDrawTexture() override;

            void Load(DependencyManager &dependencies) override;

        public:
            TiledTexture(const std::shared_ptr<BitmapSheet> &sheet, int width, int height);
            ~TiledTexture();

            void SetTile(int x, int y, Tile tile);
            void SetPalette(Palette palette);
            void SetPalette(SDL_Rect area, Palette palette);
    };
}
