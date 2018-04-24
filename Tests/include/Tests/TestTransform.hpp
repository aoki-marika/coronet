#include "TestCase.hpp"

namespace Tests
{
    class TestTransform : public TestCase
    {
        protected:
            void Load(Coronet::DependencyManager &dependencies) override;
    };
}