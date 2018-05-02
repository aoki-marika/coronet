#include <sstream>

#include "TTFFont.hpp"
#include "Bitmap.hpp"
#include "Utilities.hpp"

namespace Coronet
{
    TTFFont::TTFFont(const char *path, int ptsize)
    {
        font = TTF_OpenFont(path, ptsize);

        if (font == NULL)
        {
            std::stringstream message;
            message << "Failed to load font at '" << path << "'";
            ThrowTTFException("OpenFont", message.str());
        }
    }

    TTFFont::TTFFont(TTF_Font *font)
    {
        this->font = font;
    }

    TTFFont::TTFFont(SDL_RWops *rw, int ptsize) : TTFFont(TTF_OpenFontRW(rw, 0, ptsize))
    {
        this->rw = rw;
    }

    TTFFont::~TTFFont()
    {
        TTF_CloseFont(font);

        if (rw != nullptr)
            SDL_RWclose(rw);
    }

    std::shared_ptr<Bitmap> TTFFont::GetTextBitmap(std::string text, SDL_Color textColour)
    {
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), textColour);

        // the surface is a nullptr if the text is empty, so use a blank surface in that case
        if (textSurface == nullptr)
            textSurface = SDL_CreateRGBSurface(0, 0, 0, 8, 0, 0, 0, 0);

        return std::make_shared<Bitmap>(textSurface);
    }
}