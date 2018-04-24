#include <sstream>

#include "TestsGame.hpp"
#include "TestCase.hpp"
#include "TestSprite.hpp"
#include "TestTransforms.hpp"

namespace Tests
{
    TestsGame::TestsGame(const char *testName)
    {
        std::shared_ptr<TestCase> test;

        if (strcmp(testName, "sprite") == 0) test = std::make_shared<TestSprite>();
        if (strcmp(testName, "transforms") == 0) test = std::make_shared<TestTransforms>();
        else
        {
            std::stringstream message;
            message << "Unknown test '" << testName << "'." << std::endl;
            throw std::invalid_argument(message.str());
        }

        Add(test);
    }
}