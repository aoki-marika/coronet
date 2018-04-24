#include <Coronet/BitmapAnimation.hpp>

#include "TestAnimation.hpp"

namespace Tests
{
    void TestAnimation::LoadComplete()
    {
        TestCase::LoadComplete();

        auto animation = std::make_shared<Coronet::BitmapAnimation>();

        animation->AddFrame(std::make_shared<Coronet::Bitmap>("red.png"), 1000);
        animation->AddFrame(std::make_shared<Coronet::Bitmap>("blue.png"), 1500);
        animation->AddFrame(std::make_shared<Coronet::Bitmap>("green.png"), 2000);

        // todo: test GoToFrame when there is input handling
        animation->IsPlaying = true;
        animation->Repeat = true;
        Add(animation);
    }
}