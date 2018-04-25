#include <Coronet/Sprite.hpp>
#include <Coronet/Metrics.hpp>

#include "TestCamera.hpp"

namespace Tests
{
    TestCamera::TestCamera()
    {
        auto bitmap = std::make_shared<Coronet::Bitmap>("test.png");
        auto screen = std::make_shared<Coronet::Sprite>(bitmap);
        auto world = std::make_shared<Coronet::Sprite>(bitmap);

        // todo: indicate when the sprites are offscreen
        screen->Space = Coronet::DrawablePositionSpace::Screen;
        screen->Position = { 104, 96 };

        world->Position = { -16, 16 };

        Add(screen);
        Add(world);
    }

    void TestCamera::Load(Coronet::DependencyManager &dependencies)
    {
        TestCase::Load(dependencies);

        camera = dependencies.Get<Coronet::Camera>();
        screenSize = dependencies.Get<Coronet::Metrics>()->GetScreenSize();
    }

    void TestCamera::LoadComplete()
    {
        TestCase::LoadComplete();

        int offset = 100;

        AddTransform(Coronet::Transform(0, screenSize.x + offset, 1000, 1500, Coronet::Easing::None, [this] (double value)
        {
            camera->Position.x = value;
        }));

        AddTransform(Coronet::Transform(screenSize.x + offset, -screenSize.x - offset, 1500, 2000, Coronet::Easing::None, [this] (double value)
        {
            camera->Position.x = value;
        }));

        AddTransform(Coronet::Transform(-screenSize.x - offset, 0, 2000, 2500, Coronet::Easing::None, [this] (double value)
        {
            camera->Position.x = value;
        }));

        AddTransform(Coronet::Transform(0, screenSize.y + offset, 2500, 3000, Coronet::Easing::None, [this] (double value)
        {
            camera->Position.y = value;
        }));

        AddTransform(Coronet::Transform(screenSize.y + offset, -screenSize.y - offset, 3000, 3500, Coronet::Easing::None, [this] (double value)
        {
            camera->Position.y = value;
        }));

        AddTransform(Coronet::Transform(-screenSize.y - offset, 0, 3500, 4000, Coronet::Easing::None, [this] (double value)
        {
            camera->Position.y = value;
        }));
    }
}