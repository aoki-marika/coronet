#include <SDL2/SDL.h>

#include "GameHost.hpp"

namespace Coronet
{
    GameHost::GameHost(const char *gameName, const std::shared_ptr<Metrics> &metrics)
    {
        this->metrics = metrics;
        dependencies = DependencyManager();

        Vector2 s = metrics->GetScreenSize();
        window = std::make_shared<Window>(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, s.x, s.y, gameName);
        renderer = std::make_shared<Renderer>(window);

        dependencies.Register<Renderer>(renderer);
        dependencies.Register<Metrics>(metrics);
    }

    void GameHost::Run(const std::shared_ptr<Game> &game)
    {
        if (hostedGame != nullptr)
            throw std::invalid_argument("GameHost cannot run another Game when one is already running.");

        hostedGame = game;

        SDL_Event event;
        running = true;

        renderer->Add(game);
        renderer->Inject(dependencies);
        game->OnRun();

        while (running)
        {
            while (SDL_PollEvent(&event) != 0)
            {
                switch (event.type)
                {
                    case SDL_QUIT: Exit(); break;
                    default: break;
                }
            }

            renderer->Update();
            renderer->Draw();
        }
    }

    void GameHost::Exit()
    {
        running = false;
        hostedGame->OnExit();
    }
}