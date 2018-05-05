#include <Coronet/AssetStore.hpp>
#include <Coronet/Sprite.hpp>

#include "TestTiledTexture.hpp"

using Coronet::Palette;

namespace Tests
{
    void TestTiledTexture::Load(Coronet::DependencyManager &dependencies)
    {
        TestCase::Load(dependencies);

        auto assets = dependencies.Get<Coronet::AssetStore>();
        auto bitmap = assets->GetBitmap("test.png");
        auto background = std::make_shared<Coronet::Sprite>(bitmap);
        auto sheet = assets->GetBitmapSheet("tiles.png", 8, 8);
        auto paletteSheet = assets->GetBitmapSheet("palette-tiles.png", 16, 16);
        sheet->SetColourKey({ 255, 0, 255 });

        tiled = std::make_shared<Coronet::TiledTexture>(sheet, 10, 10);
        tiled->Position = { 0, 16 };

        paletteTiled = std::make_shared<Coronet::TiledTexture>(paletteSheet, 2, 3);
        paletteTiled->Position = { 80, 0 };

        auto sprite = std::make_shared<Coronet::Sprite>(sheet->GetTile({ 0, 0 }));
        sprite->Position = { 16, 0 };

        Add(background);
        Add(sprite);
        Add(tiled);
        Add(paletteTiled);
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

        int white = 255;
        int lgray = 170;
        int dgray = 85;
        int black = 0;

        auto paletteOne = Palette();
        paletteOne.Swap[white] = { 246, 213, 230 };
        paletteOne.Swap[lgray] = { 255, 197, 156 };
        paletteOne.Swap[dgray] = { 246, 49, 82 };
        paletteOne.Swap[black] = { 57, 57, 57 };

        auto paletteTwo = Palette();
        paletteTwo.Swap[white] = { 213, 139, 197 };
        paletteTwo.Swap[lgray] = { 172, 57, 139 };
        paletteTwo.Swap[dgray] = { 131, 24, 106 };
        paletteTwo.Swap[black] = { 57, 57, 57 };

        auto paletteThree = Palette();
        paletteThree.Swap[white] = { 246, 213, 230 };
        paletteThree.Swap[lgray] = { 123, 255, 131 };
        paletteThree.Swap[dgray] = { 74, 255, 74 };
        paletteThree.Swap[black] = { 57, 57, 57 };

        auto paletteFour = Palette();
        paletteFour.Swap[white] = { 246, 213, 230 };
        paletteFour.Swap[lgray] = { 255, 57, 255 };
        paletteFour.Swap[dgray] = { 255, 8, 131 };
        paletteFour.Swap[black] = { 57, 57, 57 };

        paletteTiled->SetPalette({ 0, 0, 1, 1 }, paletteOne);
        paletteTiled->SetPalette({ 1, 0, 1, 1 }, paletteTwo);
        paletteTiled->SetPalette({ 0, 1, 1, 1 }, paletteThree);
        paletteTiled->SetPalette({ 1, 1, 1, 2 }, paletteFour);

        paletteTiled->SetTile(0, 0, { 0, 0 });
        paletteTiled->SetTile(0, 1, { 0, 1 });
        paletteTiled->SetTile(1, 0, { 1, 0 });
        paletteTiled->SetTile(1, 1, { 1, 1 });
        paletteTiled->SetTile(0, 2, { 0, 2 });
    }
}