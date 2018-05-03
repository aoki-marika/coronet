#include <Coronet/Sprite.hpp>
#include <Coronet/AssetStore.hpp>

#include "TestSprite.hpp"

namespace Tests
{
    void TestSprite::Load(Coronet::DependencyManager &dependencies)
    {
        TestCase::Load(dependencies);

        auto assets = dependencies.Get<Coronet::AssetStore>();

        auto keyedBitmap = assets->GetBitmap("test.png");
        keyedBitmap->SetColourKey(255, 0, 0);

        auto background = std::make_shared<Coronet::Sprite>(assets->GetBitmap("test.png"));
        background->Position = { -16, -16 };

        Add(background);
        Add(std::make_shared<Coronet::Sprite>(keyedBitmap));
    }
}