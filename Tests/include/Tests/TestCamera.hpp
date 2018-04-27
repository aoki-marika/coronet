#include <Coronet/Camera.hpp>
#include <Coronet/Sprite.hpp>
#include <Coronet/Text.hpp>

#include "TestCase.hpp"

namespace Tests
{
    class TestCamera : public TestCase
    {
        private:
            std::shared_ptr<Coronet::Sprite> world;
            std::shared_ptr<Coronet::Text> worldVisibleText;
            std::shared_ptr<Coronet::Camera> camera;
            Coronet::Vector2 screenSize;

        protected:
            void Load(Coronet::DependencyManager &dependencies) override;
            void LoadComplete() override;

        public:
            TestCamera();
            void Update() override;
    };
}