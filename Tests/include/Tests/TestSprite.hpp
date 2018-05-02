#include <Coronet/TestCase.hpp>

namespace Tests
{
    class TestSprite : public Coronet::TestCase
    {
        protected:
            void Load(Coronet::DependencyManager &dependencies) override;
    };
}