#include <memory>

#include "Game.hpp"
#include "Renderer.hpp"
#include "Window.hpp"

namespace Coronet
{
    class GameHost
    {
        private:
            bool running = false;

            std::shared_ptr<Window> window;
            std::shared_ptr<Renderer> renderer;
            std::shared_ptr<Game> hostedGame;

        public:
            GameHost(const char *gameName);
            void Run(const std::shared_ptr<Game> &game);
            void Exit();
    };
}