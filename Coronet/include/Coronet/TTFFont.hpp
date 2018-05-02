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
            SDL_RWops *rw;

        public:
            TTFFont(const char *path, int ptsize);
            TTFFont(TTF_Font *font);
            TTFFont(SDL_RWops *rw, int ptsize);
            ~TTFFont();

            std::shared_ptr<Bitmap> GetTextBitmap(std::string text, SDL_Color textColour) override;
    };
}