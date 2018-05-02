#include <Coronet/TestCase.hpp>

namespace Tests
{
    class TestFlip : public Coronet::TestCase
    {
        protected:
            void Load(Coronet::DependencyManager &dependencies) override;
    };
}