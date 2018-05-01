#include "BitmapAnimation.hpp"

namespace Coronet
{
    BitmapAnimation::BitmapAnimation()
    {
        sprite = std::make_shared<Sprite>();
        Add(sprite);
    }

    void BitmapAnimation::DisplayFrame(const std::shared_ptr<Bitmap> &frame)
    {
        sprite->SetBitmap(frame);
    }
}