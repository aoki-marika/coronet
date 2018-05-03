#include <Coronet/TestCase.hpp>
#include <Coronet/Container.hpp>
#include <Coronet/Sprite.hpp>

namespace Tests
{
    class TestKeyInput : public Coronet::TestCase
    {
        public:
            TestKeyInput();
    };

    class TestKeyContainer : public Coronet::Container
    {
        private:
            const char *bitmapPath;
            std::shared_ptr<Coronet::Sprite> sprite;
            SDL_Keycode key;
            bool stealDown, stealUp;

        protected:
            void Load(Coronet::DependencyManager &dependencies) override;

        public:
            TestKeyContainer(const char *bitmapPath, SDL_Keycode key, bool stealDown, bool stealUp);

            bool OnKeyDown(SDL_Event event) override;
            bool OnKeyUp(SDL_Event event) override;
    };
}