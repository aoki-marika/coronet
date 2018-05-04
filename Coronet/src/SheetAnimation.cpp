#include "SheetAnimation.hpp"

namespace Coronet
{
    SheetAnimation::SheetAnimation(const std::shared_ptr<BitmapSheet> &sheet)
    {
        this->sheet = sheet;

        sprite = std::make_shared<Sprite>();
        Add(sprite);
    }

    void SheetAnimation::DisplayFrame(const Tile &frame)
    {
        sprite->SetBitmap(sheet->GetTile(frame));
    }
}