#include <iostream>

#include "GameHost.hpp"
#include "Window.hpp"

namespace Coronet
{
    GameHost::GameHost(const char *gameName)
    {
        // todo: placeholder window size
        auto window = std::make_shared<Window>(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100, 100, gameName);
        renderer = std::make_shared<Renderer>(window);
    }

    void GameHost::Run(const std::shared_ptr<Game> &game)
    {
        if (hostedGame != nullptr)
            throw std::invalid_argument("GameHost cannot run another Game when one is already running.");

        hostedGame = game;

        renderer->Add(game);
    }
}