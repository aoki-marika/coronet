#include <Coronet/TestCase.hpp>
#include <Coronet/BitmapAnimation.hpp>

namespace Tests
{
    class TestAnimation : public Coronet::TestCase
    {
        private:
            std::shared_ptr<Coronet::BitmapAnimation> animation;

        protected:
            void Load(Coronet::DependencyManager &dependencies) override;

        public:
            bool OnKeyDown(SDL_Event event) override;
    };
}