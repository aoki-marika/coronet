#include <Coronet/TestCase.hpp>
#include <Coronet/Sprite.hpp>

namespace Tests
{
    class TestTransform : public Coronet::TestCase
    {
        private:
            std::shared_ptr<Coronet::Sprite> sprite;
            Coronet::Vector2 start, end;

        protected:
            void Load(Coronet::DependencyManager &dependencies) override;
            void LoadComplete() override;
    };
}