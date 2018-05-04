#include <Coronet/TTFFont.hpp>
#include <Coronet/Text.hpp>
#include <Coronet/AssetStore.hpp>

#include "TestText.hpp"

namespace Tests
{
    void TestText::Load(Coronet::DependencyManager &dependencies)
    {
        TestCase::Load(dependencies);

        auto assets = dependencies.Get<Coronet::AssetStore>();

        auto fontOne = assets->GetTTF("HelvetiPixel.ttf", 15);
        auto fontTwo = assets->GetTTF("HelvetiPixel.ttf", 48);

        auto textOne = std::make_shared<Coronet::Text>(fontOne, "Hello, Coronet world!");
        auto textTwo = std::make_shared<Coronet::Text>(fontTwo);
        auto textThree = std::make_shared<Coronet::Text>(fontTwo, "T X E T", SDL_Colour { 255, 0, 255 });

        textTwo->SetColour({ 255, 255, 0 });
        textTwo->SetText("T E X T");

        textTwo->Position = { 0, 15 };
        textThree->Position = { 0, 50 };

        Add(textOne);
        Add(textTwo);
        Add(textThree);
    }
}