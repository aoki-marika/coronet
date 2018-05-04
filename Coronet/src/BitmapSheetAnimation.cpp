#include "BitmapSheetAnimation.hpp"

namespace Coronet
{
    BitmapSheetAnimation::BitmapSheetAnimation(const std::shared_ptr<BitmapSheet> &sheet)
    {
        this->sheet = sheet;

        sprite = std::make_shared<Sprite>();
        Add(sprite);
    }

    void BitmapSheetAnimation::DisplayFrame(const Tile &frame)
    {
        sprite->SetBitmap(sheet->GetTile(frame));
    }
}