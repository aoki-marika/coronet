#include <Coronet/Sprite.hpp>
#include <Coronet/Container.hpp>
#include <Coronet/Metrics.hpp>

#include "TestContainer.hpp"

namespace Tests
{
    void TestContainer::Load(Coronet::DependencyManager &dependencies)
    {
        TestCase::Load(dependencies);

        auto red = std::make_shared<Coronet::Bitmap>("red.png");
        auto blue = std::make_shared<Coronet::Bitmap>("blue.png");
        auto green = std::make_shared<Coronet::Bitmap>("green.png");

        auto containerOne = std::make_shared<Coronet::Container>();
        auto containerTwo = std::make_shared<Coronet::Container>();
        auto containerThree = std::make_shared<Coronet::Container>();
        auto containerFour = std::make_shared<Coronet::Container>();
        auto containerFive = std::make_shared<Coronet::Container>();

        auto bitmapOne = std::make_shared<Coronet::Sprite>(red);
        auto bitmapTwo = std::make_shared<Coronet::Sprite>(green);
        auto bitmapThree = std::make_shared<Coronet::Sprite>(blue);
        auto bitmapFour = std::make_shared<Coronet::Sprite>(green);
        auto bitmapFive = std::make_shared<Coronet::Sprite>(blue);

        Coronet::Vector2 s = dependencies.Get<Coronet::Metrics>()->GetScreenSize();
        containerOne->Position = { (s.x - 32) / 2, (s.y - 32) / 2 };

        containerTwo->Position = { -16, -16 };
        containerThree->Position = { 8, 8 };

        containerFour->Position = { 16, 16 };
        containerFive->Position = { -8, -8 };

        containerOne->Add(bitmapOne);
        containerTwo->Add(bitmapTwo);
        containerThree->Add(bitmapThree);
        containerFour->Add(bitmapFour);
        containerFive->Add(bitmapFive);

        containerOne->Add(containerTwo);
        containerTwo->Add(containerThree);

        containerOne->Add(containerFour);
        containerFour->Add(containerFive);

        containerFour->Visibility = Coronet::Visibility::Hidden;

        Add(containerOne);
    }
}