#include <Coronet/Sprite.hpp>
#include <Coronet/Metrics.hpp>

#include "TestTransforms.hpp"

namespace Tests
{
    void TestTransforms::Load(Coronet::DependencyManager &dependencies)
    {
        TestCase::Load(dependencies);


        auto bitmap = std::make_shared<Coronet::Bitmap>("test.png");
        auto sprite = std::make_shared<Coronet::Sprite>(bitmap);

        Coronet::Vector2 start = { 0, 0 };

        Coronet::Vector2 s = dependencies.Get<Coronet::Metrics>()->GetScreenSize();
        Coronet::Vector2 end = { s.x - bitmap->GetSize().x, s.y - bitmap->GetSize().y };

        sprite->AddTransform(Coronet::Transform(start.x, end.x, 1000, 2000, Coronet::Easing::None, [sprite] (double value)
        {
            sprite->Position.x = value;
        }));

        sprite->AddTransform(Coronet::Transform(start.y, end.y, 2000, 3000, Coronet::Easing::In, [sprite] (double value)
        {
            sprite->Position.y = value;
        }));

        sprite->AddTransform(Coronet::Transform(end.x, start.x, 3000, 4000, Coronet::Easing::None, [sprite] (double value)
        {
            sprite->Position.x = value;
        }));

        sprite->AddTransform(Coronet::Transform(end.y, start.y, 4000, 5000, Coronet::Easing::Out, [sprite] (double value)
        {
            sprite->Position.y = value;
        }));

        sprite->AddTransform(Coronet::Transform(start.y, end.y, 5000, 6000, Coronet::Easing::In, [sprite] (double value)
        {
            sprite->Position.y = value;
        }));

        Add(sprite);
    }
}