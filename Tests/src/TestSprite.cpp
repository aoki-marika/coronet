#include <Coronet/Sprite.hpp>

#include "TestSprite.hpp"

namespace Tests
{
    TestSprite::TestSprite()
    {
        auto keyedBitmap = std::make_shared<Coronet::Bitmap>("test.png");
        keyedBitmap->SetColourKey(255, 0, 0);

        auto background = std::make_shared<Coronet::Sprite>(std::make_shared<Coronet::Bitmap>("test.png"));
        background->Position = { -16, -16 };

        Add(background);
        Add(std::make_shared<Coronet::Sprite>(keyedBitmap));
    }
}