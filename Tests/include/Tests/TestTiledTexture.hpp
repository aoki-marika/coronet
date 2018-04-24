#include <Coronet/TiledTexture.hpp>

#include "TestCase.hpp"

namespace Tests
{
    class TestTiledTexture : public TestCase
    {
        private:
            std::shared_ptr<Coronet::TiledTexture> tiled;

        protected:
            void LoadComplete() override;

        public:
            TestTiledTexture();
    };
}