#include <functional>

#include "Container.hpp"
#include "TTFFont.hpp"
#include "Sprite.hpp"

namespace Coronet
{
    class TestBrowser : public Container
    {
        private:
            const int ITEM_HEIGHT = 12;
            int selectedItem = 0;

            std::shared_ptr<Container> items;
            std::shared_ptr<TTFFont> font;
            std::shared_ptr<Sprite> arrow;
            std::vector<std::type_index> testTypes;

            void selectItem(int index);

        public:
            std::function<void(std::type_index)> OnSelectTest;

            TestBrowser();

            void AddTest(std::type_index testType);
            bool OnKeyDown(SDL_Event event) override;
    };
}