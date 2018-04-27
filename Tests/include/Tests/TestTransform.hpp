#include <Coronet/TestCase.hpp>

namespace Tests
{
    class TestTransform : public Coronet::TestCase
    {
        protected:
            void Load(Coronet::DependencyManager &dependencies) override;
    };
}