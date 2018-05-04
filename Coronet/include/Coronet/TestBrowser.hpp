#pragma once

#include <functional>

#include "Container.hpp"
#include "TTFFont.hpp"
#include "Sprite.hpp"

namespace Coronet
{
    class TestBrowser : public Container
    {
        private:
            int firstVisibleItem = 0; //the first visible item that this is scrolled to
            int maximumItems = 0; //maximum items on screen at once
            int selectedItem = 0;

            std::shared_ptr<Container> items;
            std::shared_ptr<Sprite> arrow;
            std::vector<std::type_index> testTypes;

            void selectItem(int index);

        protected:
            void Load(DependencyManager &dependencies) override;

        public:
            std::function<void(std::type_index)> OnSelectTest;

            TestBrowser();

            void AddTest(std::type_index testType);
            bool OnKeyDown(SDL_Event event) override;
    };
}