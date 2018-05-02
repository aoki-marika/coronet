#include <Coronet/TTFFont.hpp>
#include <Coronet/Metrics.hpp>
#include <Coronet/AssetStore.hpp>

#include "TestCamera.hpp"

namespace Tests
{
    TestCamera::~TestCamera()
    {
        camera->Position = { 0, 0 };
    }

    void TestCamera::Load(Coronet::DependencyManager &dependencies)
    {
        TestCase::Load(dependencies);

        camera = dependencies.Get<Coronet::Camera>();
        screenSize = dependencies.Get<Coronet::Metrics>()->GetScreenSize();

        auto assets = dependencies.Get<Coronet::AssetStore>();

        auto bitmap = assets->GetBitmap("test.png");
        auto screenContainer = std::make_shared<Coronet::Container>();
        auto screen = std::make_shared<Coronet::Sprite>(bitmap);
        world = std::make_shared<Coronet::Sprite>(bitmap);
        worldVisibleText = std::make_shared<Coronet::Text>(assets->GetTTF("HelvetiPixel.ttf", 15));

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

    void TestCamera::LoadComplete()
    {
        TestCase::LoadComplete();

        int positionOffset = 100;

        AddRelativeTransform(0, screenSize.x + positionOffset, 1000, 500, Coronet::Easing::None, [this] (double value)
        {
            camera->Position.x = value;
        });

        AddRelativeTransform(screenSize.x + positionOffset, -screenSize.x - positionOffset, 1500, 500, Coronet::Easing::None, [this] (double value)
        {
            camera->Position.x = value;
        });

        AddRelativeTransform(-screenSize.x - positionOffset, 0, 2000, 500, Coronet::Easing::None, [this] (double value)
        {
            camera->Position.x = value;
        });

        AddRelativeTransform(0, screenSize.y + positionOffset, 2500, 500, Coronet::Easing::None, [this] (double value)
        {
            camera->Position.y = value;
        });

        AddRelativeTransform(screenSize.y + positionOffset, -screenSize.y - positionOffset, 3000, 500, Coronet::Easing::None, [this] (double value)
        {
            camera->Position.y = value;
        });

        AddRelativeTransform(-screenSize.y - positionOffset, 0, 3500, 500, Coronet::Easing::None, [this] (double value)
        {
            camera->Position.y = value;
        });
    }

    void TestCamera::Update()
    {
        TestCase::Update();

        worldVisibleText->Visibility = world->IsVisible() ? Coronet::Visibility::Visible : Coronet::Visibility::Hidden;
    }
}