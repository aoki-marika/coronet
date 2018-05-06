#include <sstream>
#include <SDL2/SDL_image.h>

#include "Bitmap.hpp"
#include "Utilities.hpp"
#include "Logging.hpp"

namespace Coronet
{
    Bitmap::Bitmap(const char *path)
    {
        SDL_Surface *image = IMG_Load(path);

        if (image == nullptr)
        {
            std::stringstream message;
            message << "Failed to load image at '" << path << "'";
            ThrowIMGException("Load", message.str());
        }
        else
        {
            size = { image->w, image->h };
            surface = image;
        }
    }

    Bitmap::Bitmap(SDL_Surface *surface)
    {
        this->surface = surface;
        size = { surface->w, surface->h };
    }

    Bitmap::Bitmap(SDL_RWops *rw) : Bitmap(IMG_Load_RW(rw, 0))
    {
        this->rw = rw;
    }

    Bitmap::~Bitmap()
    {
        SDL_FreeSurface(surface);

        if (rw != nullptr)
            SDL_RWclose(rw);
    }

    bool Bitmap::HasPalette()
    {
        return hasPalette;
    }

    SDL_Surface *Bitmap::GetSurface()
    {
        return surface;
    }

    Uint32 Bitmap::GetColourKey()
    {
        Uint32 key;
        SDL_GetColorKey(surface, &key);

        return key;
    }

    Palette Bitmap::GetPalette()
    {
        return palette;
    }

    Vector2 Bitmap::GetSize()
    {
        return size;
    }

    bool Bitmap::IsColourKeyed()
    {
        return colourKeyed;
    }

    void Bitmap::SetColourKey(SDL_Color colour)
    {
        SetColourKey(SDL_MapRGB(surface->format, colour.r, colour.g, colour.b));
    }

    void Bitmap::SetColourKey(Uint32 colour)
    {
        SDL_SetColorKey(surface, SDL_TRUE, colour);
        colourKeyed = true;
    }

    void Bitmap::SetPalette(Palette palette)
    {
        auto pal = surface->format->palette;

        if (pal != nullptr)
        {
            SDL_Color colours[pal->ncolors];

            for (int i = 0; i < pal->ncolors; i++)
            {
                auto colour = pal->colors[i];

                for (auto &c : palette.Swap)
                    if (i == c.first)
                        colour = c.second;

                colours[i] = colour;
            }

            hasPalette = true;
            this->palette = palette;
            SDL_SetPaletteColors(pal, colours, 0, pal->ncolors);
        }
        else
        {
            Log(LogLevel::Warning) << "Cannot set the palette of an SDL_Surface without a paletted format.";
        }
    }

    SDL_Texture *Bitmap::ToTexture(SDL_Renderer *renderer)
    {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

        if (colourKeyed)
            SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);

        return texture;
    }
}