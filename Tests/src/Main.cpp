#include <iostream>
#include <Coronet/GameHost.hpp>
#include <Coronet/TestGame.hpp>
#include <Coronet/AssetStore.hpp>
#include <Coronet/AssetBitmap.hpp>
#include <Coronet/AssetTTFFont.hpp>
#include <SDL2/SDL_image.h>

#include "TestSprite.hpp"
#include "TestContainer.hpp"
#include "TestCamera.hpp"
#include "TestTransform.hpp"
#include "TestTiledTexture.hpp"
#include "TestAnimation.hpp"
#include "TestKeyInput.hpp"
#include "TestFlip.hpp"
#include "TestText.hpp"

using namespace Tests;

int main(int argc, char *argv[])
{
    auto testStore = Coronet::AssetStore();
    testStore.Mount("Coronet.assets.zip");

    auto testBitmap = testStore.Read<Coronet::AssetBitmap>("assets/Images/test-selection.png");
    auto bitmapSize = testBitmap.GetAsset()->GetSize();
    std::cout << bitmapSize.x << "," << bitmapSize.y << std::endl;

    auto testFont = testStore.Read<Coronet::AssetTTFFont>("assets/Fonts/HelvetiPixel.ttf", 15);
    auto fontBitmap = testFont.GetAsset()->GetTextBitmap("Text", { 255, 255, 255 });
    auto fontSize = fontBitmap->GetSize();
    std::cout << fontSize.x << "," << fontSize.y << std::endl;

    auto host = std::make_shared<Coronet::GameHost>("Tests", std::make_shared<Coronet::Metrics>(8, 8, 2, 2, 20, 18));
    auto game = std::make_shared<Coronet::TestGame>();

    game->RegisterTest<TestSprite>();
    game->RegisterTest<TestContainer>();
    game->RegisterTest<TestCamera>();
    game->RegisterTest<TestTransform>();
    game->RegisterTest<TestTiledTexture>();
    game->RegisterTest<TestAnimation>();
    game->RegisterTest<TestKeyInput>();
    game->RegisterTest<TestFlip>();
    game->RegisterTest<TestText>();

    host->Run(game);

    return 0;
}