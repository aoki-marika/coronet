#include <Coronet/GameHost.hpp>
#include <Coronet/TestGame.hpp>

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
    auto host = std::make_shared<Coronet::GameHost>("Tests", std::make_shared<Coronet::Metrics>(8, 8, 2, 2, 20, 18));
    auto game = std::make_shared<Coronet::TestGame>();

    game->RegisterTest<TestSprite>([] () { return std::make_shared<TestSprite>(); });
    game->RegisterTest<TestContainer>([] () { return std::make_shared<TestContainer>(); });
    game->RegisterTest<TestCamera>([] () { return std::make_shared<TestCamera>(); });
    game->RegisterTest<TestTransform>([] () { return std::make_shared<TestTransform>(); });
    game->RegisterTest<TestTiledTexture>([] () { return std::make_shared<TestTiledTexture>(); });
    game->RegisterTest<TestAnimation>([] () { return std::make_shared<TestAnimation>(); });
    game->RegisterTest<TestKeyInput>([] () { return std::make_shared<TestKeyInput>(); });
    game->RegisterTest<TestFlip>([] () { return std::make_shared<TestFlip>(); });
    game->RegisterTest<TestText>([] () { return std::make_shared<TestText>(); });

    host->Run(game);

    return 0;
}