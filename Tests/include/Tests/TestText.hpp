#include <Coronet/TestCase.hpp>

namespace Tests
{
    class TestText : public Coronet::TestCase
    {
        protected:
            void Load(Coronet::DependencyManager &dependencies) override;
    };
}