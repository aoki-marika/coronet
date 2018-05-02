#include <sstream>
#include <SDL2/SDL_image.h>

#include "Bitmap.hpp"
#include "Utilities.hpp"

namespace Coronet
{
    Bitmap::Bitmap(const char *path)
    {
        SDL_Surface *image = IMG_Load(path);

        if (image == NULL)
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
        if (surface != NULL)
            SDL_FreeSurface(surface);

        if (rw != NULL)
            SDL_RWclose(rw);
    }

    bool Bitmap::IsColourKeyed()
    {
        return colourKeyed;
    }

    Vector2 Bitmap::GetSize()
    {
        return size;
    }

    void Bitmap::SetColourKey(Uint8 r, Uint8 g, Uint8 b)
    {
        SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, r, g, b));
        colourKeyed = true;
    }

    SDL_Texture *Bitmap::ToTexture(SDL_Renderer *renderer)
    {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

        if (colourKeyed)
            SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);

        return texture;
    }
}