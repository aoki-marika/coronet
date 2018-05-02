#pragma once

#include <string>
#include <SDL2/SDL_ttf.h>

#include "Font.hpp"

namespace Coronet
{
    class TTFFont : public Font
    {
        private:
            TTF_Font *font;

        public:
            TTFFont(const char *path, int ptsize);
            TTFFont(TTF_Font *font);
            ~TTFFont();

            std::shared_ptr<Bitmap> GetTextBitmap(std::string text, SDL_Color textColour) override;
    };
}