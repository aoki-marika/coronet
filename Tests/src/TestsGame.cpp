#include <sstream>

#include "TestsGame.hpp"
#include "TestCase.hpp"
#include "TestSprite.hpp"
#include "TestContainer.hpp"
#include "TestCamera.hpp"
#include "TestTransform.hpp"
#include "TestTiledTexture.hpp"

namespace Tests
{
    TestsGame::TestsGame(const char *testName)
    {
        std::shared_ptr<TestCase> test;

        if (strcmp(testName, "Sprite") == 0) test = std::make_shared<TestSprite>();
        else if (strcmp(testName, "Container") == 0) test = std::make_shared<TestContainer>();
        else if (strcmp(testName, "Camera") == 0) test = std::make_shared<TestCamera>();
        else if (strcmp(testName, "Transform") == 0) test = std::make_shared<TestTransform>();
        else if (strcmp(testName, "TiledTexture") == 0) test = std::make_shared<TestTiledTexture>();
        else
        {
            std::stringstream message;
            message << "Unknown test '" << testName << "'." << std::endl;
            throw std::invalid_argument(message.str());
        }

        Add(test);
    }
}