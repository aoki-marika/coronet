#pragma once

#include <SDL2/SDL.h>

#include "Vector2.hpp"

namespace Coronet
{
    class Bitmap
    {
        private:
            Vector2 size;
            SDL_Surface *surface;
            SDL_RWops *rw = nullptr;
            bool colourKeyed = false;

        protected:
            SDL_Surface *GetSurface();
            SDL_Color GetColourKey();

        public:
            Bitmap(const char *path);
            Bitmap(SDL_Surface *surface);
            Bitmap(SDL_RWops *rw);
            ~Bitmap();

            Vector2 GetSize();
            bool IsColourKeyed();
            void SetColourKey(Uint8 r, Uint8 g, Uint8 b);
            SDL_Texture *ToTexture(SDL_Renderer *renderer);
    };
}