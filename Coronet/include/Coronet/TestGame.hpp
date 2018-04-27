#include <typeindex>
#include <functional>
#include <map>
#include <sstream>

#include "Game.hpp"
#include "TestCase.hpp"

namespace Coronet
{
    class TestGame : public Game
    {
        private:
            std::map<std::type_index, std::function<std::shared_ptr<TestCase>()>> tests;
            std::shared_ptr<TestCase> currentTest;

        public:
            TestGame();

            virtual void OnRun() override;

            // not a huge fan of this implementation, but C++
            // generic types cannot do what I want them to.
            template <typename T> void RegisterTest(std::function<std::shared_ptr<TestCase>()> createTest)
            {
                (void)static_cast<TestCase *>((T *)0);

                tests[typeid(T)] = createTest;
            }

            template <typename T> void ShowTest()
            {
                (void)static_cast<TestCase *>((T *)0);

                if (currentTest != nullptr)
                    Remove(currentTest);

                auto find = tests.find(typeid(T));

                if (find != tests.end())
                {
                    currentTest = tests[typeid(T)]();
                    Add(currentTest);
                }
                else
                {
                    std::stringstream message;
                    message << "Test for type <" << Demangle(typeid(T).name()) << "> is not registered.";
                    throw std::invalid_argument(message.str());
                }
            }
    };
}