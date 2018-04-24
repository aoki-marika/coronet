#include <Coronet/Sprite.hpp>

#include "TestCase.hpp"

namespace Tests
{
    class TestSprite : public TestCase
    {
        private:
            std::shared_ptr<Coronet::Sprite> sprite;

        public:
            TestSprite();

            void Update() override;
    };
}