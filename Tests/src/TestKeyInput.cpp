#include "TestKeyInput.hpp"

namespace Tests
{
    TestKeyInput::TestKeyInput()
    {
        auto f = std::make_shared<TestKeyContainer>("red.png", SDLK_f, true, false);
        auto g = std::make_shared<TestKeyContainer>("green.png", SDLK_g, false, true);
        auto h = std::make_shared<TestKeyContainer>("blue.png", SDLK_h, true, true);

        auto fTwo = std::make_shared<TestKeyContainer>("red.png", SDLK_f, false, false);
        auto gTwo = std::make_shared<TestKeyContainer>("green.png", SDLK_g, false, false);
        auto hTwo = std::make_shared<TestKeyContainer>("blue.png", SDLK_h, false, false);

        g->Position = { 32, 0 };
        h->Position = { 64, 0 };

        fTwo->Position = { 0, 32 };
        gTwo->Position = { 32, 32 };
        hTwo->Position = { 64, 32 };

        Add(fTwo);
        Add(gTwo);
        Add(hTwo);

        Add(f);
        Add(g);
        Add(h);
    }

    TestKeyContainer::TestKeyContainer(const char *bitmapPath, SDL_Keycode key, bool stealDown, bool stealUp)
    {
        this->key = key;
        this->stealDown = stealDown;
        this->stealUp = stealUp;

        sprite = std::make_shared<Coronet::Sprite>(std::make_shared<Coronet::Bitmap>(bitmapPath));
        sprite->Visibility = Coronet::Visibility::Hidden;

        Add(sprite);
    }

    bool TestKeyContainer::OnKeyDown(SDL_Event event)
    {
        if (event.key.keysym.sym == key)
        {
            sprite->Visibility = Coronet::Visibility::Visible;

            if (stealDown)
                return true;
        }

        return Container::OnKeyDown(event);
    }

    bool TestKeyContainer::OnKeyUp(SDL_Event event)
    {
        if (event.key.keysym.sym == key)
        {
            sprite->Visibility = Coronet::Visibility::Hidden;

            if (stealUp)
                return true;
        }

        return Container::OnKeyUp(event);
    }
}