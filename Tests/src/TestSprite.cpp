#include "TestSprite.hpp"

namespace Tests
{
    TestSprite::TestSprite()
    {
        sprite = std::make_shared<Coronet::Sprite>(std::make_shared<Coronet::Bitmap>("test.png"));
        Add(sprite);
    }

    void TestSprite::Update()
    {
        TestCase::Update();

        sprite->Position = sprite->Position += { 1, 1 };
    }
}