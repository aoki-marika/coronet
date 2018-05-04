#pragma once

#include <typeindex>

#include "Container.hpp"

namespace Coronet
{
    class TestBrowserItem : public Container
    {
        private:
            std::type_index type;

        protected:
            void Load(DependencyManager &dependencies) override;

        public:
            static const int HEIGHT = 12;

            TestBrowserItem(std::type_index type);
    };
}