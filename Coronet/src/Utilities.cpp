#include <sstream>
#include <iostream>
#include <SDL2/SDL.h>

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
}