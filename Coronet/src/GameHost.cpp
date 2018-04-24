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
        clock = std::make_shared<Clock>();

        dependencies.Register<Metrics>(metrics);
        dependencies.Register<Renderer>(renderer);
        dependencies.Register<Clock>(clock);
    }

    void GameHost::Run(const std::shared_ptr<Game> &game)
    {
        if (hostedGame != nullptr)
            throw std::invalid_argument("GameHost cannot run another Game when one is already running.");

        hostedGame = game;

        clock->Start();
        renderer->Add(game);
        renderer->Inject(dependencies);
        game->OnRun();

        SDL_Event event;
        Uint32 nextGameTick = SDL_GetTicks();
        running = true;

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

            // todo: this works for now but should be revisited when Update and Draw are heavier to see the effects
            while (SDL_GetTicks() > nextGameTick)
            {
                clock->SetTicks(nextGameTick);
                renderer->Update();

                nextGameTick += 1;
            }

            renderer->Draw();
        }
    }

    void GameHost::Exit()
    {
        running = false;
        hostedGame->OnExit();
    }
}