#include <memory>

#include "Game.hpp"
#include "Renderer.hpp"

namespace Coronet
{
    class GameHost
    {
        private:
            std::shared_ptr<Renderer> renderer;
            std::shared_ptr<Game> hostedGame;

        public:
            GameHost(const char *gameName);
            void Run(const std::shared_ptr<Game> &game);
    };
}