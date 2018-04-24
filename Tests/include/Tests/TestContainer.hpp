#include "TestCase.hpp"

namespace Tests
{
    class TestContainer : public TestCase
    {
        public:
            void Load(Coronet::DependencyManager &dependencies) override;
    };
}