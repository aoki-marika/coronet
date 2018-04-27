#pragma once

#include <SDL2/SDL.h>

#include "Bitmap.hpp"

namespace Coronet
{
    class Font
    {
        public:
            virtual std::shared_ptr<Bitmap> GetTextBitmap(std::string text, SDL_Color textColour) = 0;
    };
}