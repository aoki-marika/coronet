#include <Coronet/TTFFont.hpp>
#include <Coronet/Metrics.hpp>

#include "TestCamera.hpp"

namespace Tests
{
    TestCamera::TestCamera()
    {
        auto bitmap = std::make_shared<Coronet::Bitmap>("test.png");
        auto screenContainer = std::make_shared<Coronet::Container>();
        auto screen = std::make_shared<Coronet::Sprite>(bitmap);
        world = std::make_shared<Coronet::Sprite>(bitmap);
        worldVisibleText = std::make_shared<Coronet::Text>(std::make_shared<Coronet::TTFFont>("HelvetiPixel.ttf", 15));

        screenContainer->Space = Coronet::DrawablePositionSpace::Screen;
        screenContainer->Position = { 104, 96 };

        world->Position = { -16, 16 };

        worldVisibleText->Space = Coronet::DrawablePositionSpace::Screen;
        worldVisibleText->SetText("world is visible");

        screenContainer->Add(screen);

        Add(screenContainer);
        Add(world);
        Add(worldVisibleText);
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

    void TestCamera::Update()
    {
        TestCase::Update();

        worldVisibleText->Visibility = world->IsVisible() ? Coronet::Visibility::Visible : Coronet::Visibility::Hidden;
    }
}