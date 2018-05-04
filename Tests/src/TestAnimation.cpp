#include <Coronet/AssetStore.hpp>
#include <Coronet/SheetAnimation.hpp>

#include "TestAnimation.hpp"

namespace Tests
{
    void TestAnimation::Load(Coronet::DependencyManager &dependencies)
    {
        TestCase::Load(dependencies);

        auto assets = dependencies.Get<Coronet::AssetStore>();

        bitmapAnimation = std::make_shared<Coronet::BitmapAnimation>();
        auto sheet = assets->GetBitmapSheet("tiles.png", 8, 8);
        auto sheetAnimation = std::make_shared<Coronet::SheetAnimation>(sheet);

        sheet->SetColourKey(255, 0, 255);

        bitmapAnimation->AddFrame(assets->GetBitmap("red.png"), 1000);
        bitmapAnimation->AddFrame(assets->GetBitmap("blue.png"), 1500);
        bitmapAnimation->AddFrame(assets->GetBitmap("green.png"), 2000);

        sheetAnimation->AddFrame({ 0, 0 }, 500);
        sheetAnimation->AddFrame({ 0, 1 }, 500);
        sheetAnimation->AddFrame({ 1, 0 }, 500);
        sheetAnimation->AddFrame({ 1, 1 }, 500);

        bitmapAnimation->IsPlaying = true;
        bitmapAnimation->Repeat = true;

        sheetAnimation->Position = { 64, 0 };
        sheetAnimation->IsPlaying = true;
        sheetAnimation->Repeat = true;

        Add(bitmapAnimation);
        Add(sheetAnimation);
    }

    bool TestAnimation::OnKeyDown(SDL_Event event)
    {
        if (event.key.keysym.sym == SDLK_1)
        {
            bitmapAnimation->GoToFrame(1);
            return true;
        }

        return TestCase::OnKeyDown(event);
    }
}