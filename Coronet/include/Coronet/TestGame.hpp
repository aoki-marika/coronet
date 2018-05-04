#pragma once

#include <typeindex>
#include <functional>
#include <map>

#include "Game.hpp"
#include "TestCase.hpp"
#include "TestBrowser.hpp"

namespace Coronet
{
    class TestGame : public Game
    {
        private:
            std::map<std::type_index, std::function<std::shared_ptr<TestCase>()>> tests;
            std::shared_ptr<TestCase> currentTest;
            std::shared_ptr<TestBrowser> browser;

            void showTest(std::type_index testType);

        public:
            TestGame();

            virtual bool OnKeyDown(SDL_Event event) override;

            template <typename T> void RegisterTest()
            {
                // ensure that T is a TestCase
                (void)static_cast<TestCase *>((T *)0);

                tests[typeid(T)] = [] ()
                {
                    return std::make_shared<T>();
                };

                browser->AddTest(typeid(T));
            }
    };
}