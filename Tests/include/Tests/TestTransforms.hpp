#include "TestCase.hpp"

namespace Tests
{
    // todo: TestTransforms -> TestTransform
    class TestTransforms : public TestCase
    {
        protected:
            void Load(Coronet::DependencyManager &dependencies) override;
    };
}