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
        keyedBitmap->SetColourKey({ 255, 0, 0 });

        auto background = std::make_shared<Coronet::Sprite>(assets->GetBitmap("test.png"));
        background->Position = { -16, -16 };

        auto paletteBitmap = assets->GetBitmap("paletted.png");
        auto paletteSprite = std::make_shared<Coronet::Sprite>(paletteBitmap);
        auto palette = Coronet::Palette();

        palette.Swap[255] = { 246, 213, 230 };
        palette.Swap[170] = { 255, 197, 156 };
        palette.Swap[85] = { 246, 49, 82 };
        palette.Swap[0] = { 57, 57, 57 };

        paletteBitmap->SetPalette(palette);
        paletteSprite->Position = { 32, 0 };

        Add(background);
        Add(std::make_shared<Coronet::Sprite>(keyedBitmap));
        Add(paletteSprite);
    }
}