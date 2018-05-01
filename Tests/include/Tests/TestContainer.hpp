#include <Coronet/TestCase.hpp>

namespace Tests
{
    class TestContainer : public Coronet::TestCase
    {
        public:
            void Load(Coronet::DependencyManager &dependencies) override;
    };
}