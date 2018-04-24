#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cxxabi.h>

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

    std::string Demangle(const char *name)
    {
        int status;

        std::unique_ptr<char, void(*)(void*)> demangled {
            abi::__cxa_demangle(name, NULL, NULL, &status),
            std::free
        };

        return status == 0 ? demangled.get() : name;
    }
}