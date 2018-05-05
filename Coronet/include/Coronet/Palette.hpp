#include <map>
#include <SDL2/SDL.h>

namespace Coronet
{
    struct Palette
    {
        std::map<int, SDL_Colour> Swap;
    };
}