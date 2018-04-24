#include "TestTiledTexture.hpp"

namespace Tests
{
    TestTiledTexture::TestTiledTexture()
    {
        auto sheet = std::make_shared<Coronet::BitmapSheet>("tiles.png", 8, 8);
        sheet->SetColourKey(255, 0, 255);

        tiled = std::make_shared<Coronet::TiledTexture>(sheet, 10, 10);

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