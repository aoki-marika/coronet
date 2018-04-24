#pragma once

#include <memory>

#include "DependencyManager.hpp"

namespace Coronet
{
    enum class DrawableLoadState
    {
        Unloaded = 0,
        Loaded
    };

    class Drawable
    {
        protected:
            DrawableLoadState State;

            virtual void Load(DependencyManager &dependencies);
            virtual void LoadComplete();

        public:
            std::weak_ptr<Drawable> Parent;

            Drawable();
            ~Drawable();

            // todo: dont like callComplete
            virtual void Inject(DependencyManager &dependencies, bool callComplete = true);
            virtual void Update();
            virtual void Draw();
    };
}