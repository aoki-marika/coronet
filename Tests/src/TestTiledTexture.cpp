#include <Coronet/AssetStore.hpp>
#include <Coronet/Sprite.hpp>

#include "TestTiledTexture.hpp"

namespace Tests
{
    void TestTiledTexture::Load(Coronet::DependencyManager &dependencies)
    {
        TestCase::Load(dependencies);

        auto assets = dependencies.Get<Coronet::AssetStore>();
        auto bitmap = assets->GetBitmap("test.png");
        auto background = std::make_shared<Coronet::Sprite>(bitmap);
        auto sheet = assets->GetBitmapSheet("tiles.png", 8, 8);
        sheet->SetColourKey(255, 0, 255);

        tiled = std::make_shared<Coronet::TiledTexture>(sheet, 10, 10);
        tiled->Position = { 0, 16 };

        auto sprite = std::make_shared<Coronet::Sprite>(sheet->GetTile({ 0, 0 }));
        sprite->Position = { 16, 0 };

        Add(background);
        Add(sprite);
        Add(tiled);
    }

    void TestTiledTexture::LoadComplete()
    {
        TestCase::LoadComplete();

        int tileX = 0;
        int tileY = 0;
        for (int x = 0; x < 10; x++)
        {
            if (tileY >= 2)
                tileY = 0;

            for (int y = 0; y < 10; y++)
            {
                if (tileX >= 2)
                {
                    tileX = 0;
                    continue;
                }

                tiled->SetTile(x, y, Coronet::Tile(tileX, tileY));

                tileX++;
            }

            tileY++;
        }
    }
}