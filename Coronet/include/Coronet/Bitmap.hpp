#pragma once

#include <SDL2/SDL.h>

#include "Vector2.hpp"

namespace Coronet
{
    class Bitmap
    {
        private:
            Vector2 size;
            SDL_Surface *surface = NULL;
            bool colourKeyed = false;

        protected:
            bool IsColourKeyed();

        public:
            Bitmap(const char *path);
            ~Bitmap();

            Vector2 GetSize();
            void SetColourKey(Uint8 r, Uint8 g, Uint8 b);
            SDL_Texture *ToTexture(SDL_Renderer *renderer);
    };
}