#pragma once

#include <vector>

#include "Drawable.hpp"

namespace Coronet
{
    class Container : public Drawable, public std::enable_shared_from_this<Container>
    {
        private:
            DependencyManager dependencies;
            std::vector<std::shared_ptr<Drawable>> children;

        public:
            void Inject(DependencyManager &dependencies, bool callComplete = true) override;
            void Add(const std::shared_ptr<Drawable> &drawable);
            void Remove(const std::shared_ptr<Drawable> &drawable);
            virtual void Update() override;
            virtual void Draw(SDL_Renderer *renderer) override;
    };
}