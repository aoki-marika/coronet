#include <sstream>

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

    Bitmap::~Bitmap()
    {
        if (surface != NULL)
            SDL_FreeSurface(surface);
    }

    Vector2 Bitmap::GetSize()
    {
        return size;
    }
}