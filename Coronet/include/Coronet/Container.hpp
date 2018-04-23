#pragma once

#include <vector>

#include "Drawable.hpp"

namespace Coronet
{
    class Container : public Drawable, public std::enable_shared_from_this<Container>
    {
        private:
            std::vector<std::shared_ptr<Drawable>> children;

        public:
            Container();
            ~Container();

            void Add(const std::shared_ptr<Drawable> &drawable);
            void Remove(const std::shared_ptr<Drawable> &drawable);
            void Update() override;
    };
}