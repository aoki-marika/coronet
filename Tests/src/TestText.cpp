#include <Coronet/TTFFont.hpp>
#include <Coronet/Text.hpp>

#include "TestText.hpp"

namespace Tests
{
    TestText::TestText()
    {
        auto fontOne = std::make_shared<Coronet::TTFFont>("HelvetiPixel.ttf", 15);
        auto fontTwo = std::make_shared<Coronet::TTFFont>("HelvetiPixel.ttf", 48);

        auto textOne = std::make_shared<Coronet::Text>(fontOne);
        auto textTwo = std::make_shared<Coronet::Text>(fontTwo);
        auto textThree = std::make_shared<Coronet::Text>(fontTwo);

        textOne->SetText("Hello, Coronet world!");
        textThree->SetText("T X E T");

        textTwo->SetColour({ 255, 255, 0 });
        textThree->SetColour({ 255, 0, 255 });

        textTwo->SetText("T E X T");

        textTwo->Position = { 0, 15 };
        textThree->Position = { 0, 50 };

        Add(textOne);
        Add(textTwo);
        Add(textThree);
    }
}