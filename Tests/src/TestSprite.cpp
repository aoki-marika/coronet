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

        Coronet::Vector2 offset = { 1, 1 };
        sprite->Position = sprite->Position + offset;
    }
}