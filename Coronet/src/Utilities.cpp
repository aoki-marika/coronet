#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Utilities.hpp"

namespace Coronet
{
    void ThrowSDLException(std::string method, std::string message)
    {
        std::stringstream details;
        details << "SDL_" << method << " Error: " << message << ", " << SDL_GetError();

        SDL_Quit();
        throw std::logic_error(details.str());
    }

    void ThrowIMGException(std::string method, std::string message)
    {
        std::stringstream details;
        details << "IMG_" << method << " Error: " << message << ", " << IMG_GetError();

        IMG_Quit();
        SDL_Quit();
        throw std::logic_error(details.str());
    }
}