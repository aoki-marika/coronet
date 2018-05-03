#include <Coronet/AssetStore.hpp>

#include "TestAnimation.hpp"

namespace Tests
{
    void TestAnimation::Load(Coronet::DependencyManager &dependencies)
    {
        TestCase::Load(dependencies);

        auto assets = dependencies.Get<Coronet::AssetStore>();

        animation = std::make_shared<Coronet::BitmapAnimation>();

        animation->AddFrame(assets->GetBitmap("red.png"), 1000);
        animation->AddFrame(assets->GetBitmap("blue.png"), 1500);
        animation->AddFrame(assets->GetBitmap("green.png"), 2000);

        animation->IsPlaying = true;
        animation->Repeat = true;
        Add(animation);
    }

    bool TestAnimation::OnKeyDown(SDL_Event event)
    {
        if (event.key.keysym.sym == SDLK_1)
        {
            animation->GoToFrame(1);
            return true;
        }

        return TestCase::OnKeyDown(event);
    }
}