#include "Animation.hpp"
#include "Sprite.hpp"

namespace Coronet
{
    class BitmapAnimation : public Animation<std::shared_ptr<Bitmap>>
    {
        private:
            std::shared_ptr<Sprite> sprite;

        protected:
            void DisplayFrame(const std::shared_ptr<Bitmap> &frame) override;

        public:
            BitmapAnimation();
    };
}