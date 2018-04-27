#include <Coronet/BitmapAnimation.hpp>

#include "TestCase.hpp"

namespace Tests
{
    class TestAnimation : public TestCase
    {
        private:
            std::shared_ptr<Coronet::BitmapAnimation> animation;

        protected:
            void LoadComplete() override;

        public:
            bool OnKeyDown(SDL_Event event) override;
    };
}