#include <Coronet/Sprite.hpp>
#include <Coronet/Container.hpp>
#include <Coronet/AssetStore.hpp>

#include "TestFlip.hpp"

namespace Tests
{
    void TestFlip::Load(Coronet::DependencyManager &dependencies)
    {
        TestCase::Load(dependencies);

        auto directions = dependencies.Get<Coronet::AssetStore>()->GetBitmap("directions.png");

        // end result should be (from left to right):
        //
        // first sprite flipped vertically and horizontally
        // second sprite flipped vertically
        // third sprite flipped horizontally
        // fourth sprite flipped horizontally

        auto flipBoth = std::make_shared<Coronet::Sprite>(directions);
        auto nestedFlipNone = std::make_shared<Coronet::Sprite>(directions);
        auto nestedFlipBoth = std::make_shared<Coronet::Sprite>(directions);
        auto nestedTwiceFlipBoth = std::make_shared<Coronet::Sprite>(directions);

        auto flipVerticalContainer = std::make_shared<Coronet::Container>();
        auto nestedFlipNoneContainer = std::make_shared<Coronet::Container>();

        flipVerticalContainer->Position = { 32, 0 };
        nestedFlipBoth->Position = { 32, 0 };
        nestedFlipNoneContainer->Position = { 64, 0 };

        flipBoth->Flip = Coronet::Flip::Horizontal | Coronet::Flip::Vertical;
        flipVerticalContainer->Flip = Coronet::Flip::Vertical;
        nestedFlipBoth->Flip = Coronet::Flip::Vertical | Coronet::Flip::Horizontal;
        nestedTwiceFlipBoth->Flip = Coronet::Flip::Vertical | Coronet::Flip::Horizontal;

        flipVerticalContainer->Add(nestedFlipNone);
        flipVerticalContainer->Add(nestedFlipBoth);
        flipVerticalContainer->Add(nestedFlipNoneContainer);
        nestedFlipNoneContainer->Add(nestedTwiceFlipBoth);

        Add(flipBoth);
        Add(flipVerticalContainer);
    }
}