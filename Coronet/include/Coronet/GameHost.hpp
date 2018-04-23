#include <memory>

#include "Game.hpp"

namespace Coronet
{
    class GameHost
    {
        public:
            GameHost(const char *windowTitle);
            void Run(const std::shared_ptr<Game> &game);
    };
}