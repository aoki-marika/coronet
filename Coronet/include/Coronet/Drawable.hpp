#pragma once

#include <memory>

namespace Coronet
{
    class Drawable
    {
        public:
            std::weak_ptr<Drawable> Parent;

            Drawable();
            ~Drawable();
    };
}