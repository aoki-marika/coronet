#include <Coronet/Metrics.hpp>
#include <Coronet/AssetStore.hpp>

#include "TestTransform.hpp"

namespace Tests
{
    void TestTransform::Load(Coronet::DependencyManager &dependencies)
    {
        TestCase::Load(dependencies);

        auto bitmap = dependencies.Get<Coronet::AssetStore>()->GetBitmap("test.png");
        sprite = std::make_shared<Coronet::Sprite>(bitmap);

        start = { 0, 0 };

        auto s = dependencies.Get<Coronet::Metrics>()->GetScreenSize();
        end = { s.x - bitmap->GetSize().x, s.y - bitmap->GetSize().y };

        Add(sprite);
    }

    void TestTransform::LoadComplete()
    {
        TestCase::LoadComplete();

        sprite->AddRelativeTransform(start.x, end.x, 1000, 1000, Coronet::Easing::None, [this] (double value)
        {
            this->sprite->Position.x = value;
        });

        sprite->AddRelativeTransform(start.y, end.y, 2000, 1000, Coronet::Easing::In, [this] (double value)
        {
            this->sprite->Position.y = value;
        });

        sprite->AddRelativeTransform(end.x, start.x, 3000, 1000, Coronet::Easing::None, [this] (double value)
        {
            this->sprite->Position.x = value;
        });

        sprite->AddRelativeTransform(end.y, start.y, 4000, 1000, Coronet::Easing::Out, [this] (double value)
        {
            this->sprite->Position.y = value;
        });

        sprite->AddRelativeTransform(start.y, end.y, 5000, 1000, Coronet::Easing::In, [this] (double value)
        {
            this->sprite->Position.y = value;
        });
    }
}