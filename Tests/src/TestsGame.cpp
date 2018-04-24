#include <sstream>

#include "TestsGame.hpp"
#include "TestCase.hpp"
#include "TestSprite.hpp"
#include "TestContainer.hpp"
#include "TestCamera.hpp"
#include "TestTransform.hpp"

namespace Tests
{
    TestsGame::TestsGame(const char *testName)
    {
        std::shared_ptr<TestCase> test;

        if (strcmp(testName, "sprite") == 0) test = std::make_shared<TestSprite>();
        else if (strcmp(testName, "container") == 0) test = std::make_shared<TestContainer>();
        else if (strcmp(testName, "camera") == 0) test = std::make_shared<TestCamera>();
        else if (strcmp(testName, "transform") == 0) test = std::make_shared<TestTransform>();
        else
        {
            std::stringstream message;
            message << "Unknown test '" << testName << "'." << std::endl;
            throw std::invalid_argument(message.str());
        }

        Add(test);
    }
}