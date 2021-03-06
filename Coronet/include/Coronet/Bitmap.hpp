#pragma once

#include <SDL2/SDL.h>

#include "Vector2.hpp"
#include "Palette.hpp"

namespace Coronet
{
    class Bitmap
    {
        private:
            Vector2 size;
            SDL_Surface *surface;
            SDL_RWops *rw = nullptr;
            bool colourKeyed = false;
            Palette palette;
            bool hasPalette = false;

        protected:
            bool HasPalette();
            SDL_Surface *GetSurface();
            Uint32 GetColourKey();
            Palette GetPalette();

        public:
            Bitmap(const char *path);
            Bitmap(SDL_Surface *surface);
            Bitmap(SDL_RWops *rw);
            ~Bitmap();

            Vector2 GetSize();
            bool IsColourKeyed();
            void SetColourKey(SDL_Colour colour);
            void SetColourKey(Uint32 colour);
            void SetPalette(Palette palette);
            SDL_Texture *ToTexture(SDL_Renderer *renderer);
    };
}