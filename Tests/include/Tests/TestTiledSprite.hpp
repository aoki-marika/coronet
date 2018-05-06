#include <Coronet/TestCase.hpp>
#include <Coronet/TiledSprite.hpp>

namespace Tests
{
    class TestTiledSprite : public Coronet::TestCase
    {
        private:
            std::shared_ptr<Coronet::TiledSprite> tiled, paletteTiled;

            void setTiles();
            void setPalettes();

        protected:
            void Load(Coronet::DependencyManager &dependencies) override;
    };
}