#include <iostream>
#include <Coronet/GameHost.hpp>
#include <Coronet/TestGame.hpp>
#include <Coronet/AssetStore.hpp>
#include <Coronet/AssetBitmap.hpp>
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
    testStore.Mount("Tests.assets.zip");
    auto testAsset = testStore.Read<Coronet::AssetBitmap>("assets/Images/blue.png");
    auto size = testAsset.GetAsset()->GetSize();
    std::cout << size.x << "," << size.y << std::endl;

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