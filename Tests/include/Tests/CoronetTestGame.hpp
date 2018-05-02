#include <Coronet/TestGame.hpp>

namespace Tests
{
    class CoronetTestGame : public Coronet::TestGame
    {
        protected:
            void Load(Coronet::DependencyManager &dependencies) override;
    };
}