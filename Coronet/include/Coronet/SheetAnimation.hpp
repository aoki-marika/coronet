#pragma once

#include "Animation.hpp"
#include "Tile.hpp"
#include "BitmapSheet.hpp"
#include "Sprite.hpp"

namespace Coronet
{
    class SheetAnimation : public Animation<Tile>
    {
        private:
            std::shared_ptr<BitmapSheet> sheet;
            std::shared_ptr<Sprite> sprite;

        protected:
            void DisplayFrame(const Tile &frame);

        public:
            SheetAnimation(const std::shared_ptr<BitmapSheet> &sheet);
    };
}