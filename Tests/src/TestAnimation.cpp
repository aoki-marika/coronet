#include "TestAnimation.hpp"

namespace Tests
{
    void TestAnimation::LoadComplete()
    {
        TestCase::LoadComplete();

        animation = std::make_shared<Coronet::BitmapAnimation>();

        animation->AddFrame(std::make_shared<Coronet::Bitmap>("red.png"), 1000);
        animation->AddFrame(std::make_shared<Coronet::Bitmap>("blue.png"), 1500);
        animation->AddFrame(std::make_shared<Coronet::Bitmap>("green.png"), 2000);

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