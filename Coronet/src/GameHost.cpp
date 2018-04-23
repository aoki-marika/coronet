#include <iostream>

#include "GameHost.hpp"
#include "Window.hpp"

namespace Coronet
{
    GameHost::GameHost(const char *windowTitle)
    {
        // todo: placeholder window size
        auto window = std::make_shared<Window>(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100, 100, windowTitle);
    }

    void GameHost::Run(const std::shared_ptr<Game> &game)
    {
    }
}