#include <memory>

#include "Game.hpp"

namespace Coronet
{
    class GameHost
    {
        public:
            void Run(const std::shared_ptr<Game> &game);
    };
}