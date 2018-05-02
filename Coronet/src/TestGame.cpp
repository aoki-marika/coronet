#include "TestGame.hpp"

namespace Coronet
{
    TestGame::TestGame()
    {
        browser = std::make_shared<TestBrowser>();

        browser->OnSelectTest = [this] (auto test)
        {
            this->showTest(test);
        };

        Add(browser);
    }

    void TestGame::showTest(std::type_index testType)
    {
        if (currentTest != nullptr)
        {
            Remove(currentTest);
            currentTest.reset();
        }

        currentTest = tests[testType]();
        Add(currentTest);

        browser->Hide();
    }

    bool TestGame::OnKeyDown(SDL_Event event)
    {
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            if (currentTest != nullptr)
            {
                Remove(currentTest);
                currentTest.reset();
                browser->Show();

                return true;
            }
        }

        return Game::OnKeyDown(event);
    }
}