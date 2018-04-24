#include <Coronet/Sprite.hpp>

#include "TestSprite.hpp"

namespace Tests
{
    TestSprite::TestSprite()
    {
        Add(std::make_shared<Coronet::Sprite>(std::make_shared<Coronet::Bitmap>("test.png")));
    }
}