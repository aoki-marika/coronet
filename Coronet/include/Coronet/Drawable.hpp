#pragma once

#include <memory>
#include <SDL2/SDL.h>

#include "DependencyManager.hpp"
#include "Vector2.hpp"
#include "Transformable.hpp"
#include "GameClock.hpp"

namespace Coronet
{
    enum class DrawableLoadState
    {
        Unloaded,
        Loaded
    };

    class Drawable : public Transformable
    {
        private:
            std::shared_ptr<GameClock> clock;

        protected:
            DrawableLoadState State = DrawableLoadState::Unloaded;

            virtual Vector2 GetDrawPosition();

            virtual void Load(DependencyManager &dependencies);
            virtual void LoadComplete();

        public:
            std::weak_ptr<Drawable> Parent;
            Vector2 Position = { 0, 0 };

            Drawable();
            ~Drawable();

            // todo: dont like callComplete
            virtual void Inject(DependencyManager &dependencies, bool callComplete = true);
            virtual void Update();
            virtual void Draw(SDL_Renderer *renderer);
    };
}