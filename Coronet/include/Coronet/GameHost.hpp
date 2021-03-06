#pragma once

#include <memory>

#include "Game.hpp"
#include "Renderer.hpp"
#include "Window.hpp"
#include "DependencyManager.hpp"
#include "Metrics.hpp"
#include "GameClock.hpp"
#include "Camera.hpp"
#include "AssetStore.hpp"

namespace Coronet
{
    class GameHost
    {
        private:
            bool running = false;

            DependencyManager dependencies;
            std::shared_ptr<Metrics> metrics;
            std::shared_ptr<Window> window;
            std::shared_ptr<Renderer> renderer;
            std::shared_ptr<Camera> camera;
            std::shared_ptr<GameClock> clock;
            std::shared_ptr<AssetStore> assets;
            std::shared_ptr<Game> hostedGame;

        public:
            GameHost(const char *gameName, const std::shared_ptr<Metrics> &metrics);
            void Run(const std::shared_ptr<Game> &game);
            void Exit();
    };
}