#include "TestCase.hpp"

namespace Tests
{
    class TestTransforms : public TestCase
    {
        protected:
            void Load(Coronet::DependencyManager &dependencies) override;
    };
}