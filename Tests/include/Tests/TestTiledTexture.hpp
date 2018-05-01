#include <Coronet/TestCase.hpp>
#include <Coronet/TiledTexture.hpp>

namespace Tests
{
    class TestTiledTexture : public Coronet::TestCase
    {
        private:
            std::shared_ptr<Coronet::TiledTexture> tiled;

        protected:
            void LoadComplete() override;

        public:
            TestTiledTexture();
    };
}