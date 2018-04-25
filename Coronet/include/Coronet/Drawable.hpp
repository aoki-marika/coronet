#pragma once

#include <memory>
#include <SDL2/SDL.h>

#include "DependencyManager.hpp"
#include "Vector2.hpp"
#include "Transformable.hpp"
#include "GameClock.hpp"
#include "Camera.hpp"

namespace Coronet
{
    enum class DrawableLoadState
    {
        Unloaded,
        Loaded
    };

    enum class DrawablePositionSpace
    {
        World,
        Screen
    };

    enum class Visibility
    {
        Visible,
        Hidden
    };

    class Drawable : public Transformable
    {
        private:
            std::shared_ptr<GameClock> clock;
            std::shared_ptr<Camera> camera;

        protected:
            DrawableLoadState State = DrawableLoadState::Unloaded;

            //
            // includeCamera is whether or not the camera position should be
            // factored into the returned position.
            //
            // this is needed because without it, when GetDrawPosition queries
            // the parents draw positions it includes camera position for every
            // parent and exponentially increases the draw position.
            //
            virtual Vector2 GetDrawPosition(bool includeCamera = false);
            virtual Vector2 GetDrawSize();
            virtual Visibility GetVisibility();
            virtual bool IsVisible();

            virtual void Load(DependencyManager &dependencies);
            virtual void LoadComplete();

        public:
            std::weak_ptr<Drawable> Parent;
            Vector2 Position = { 0, 0 };
            DrawablePositionSpace Space = DrawablePositionSpace::World;
            Visibility Visibility = Visibility::Visible;

            Drawable();
            ~Drawable();

            // todo: dont like callComplete
            virtual void Inject(DependencyManager &dependencies, bool callComplete = true);
            virtual void Update();
            virtual void Draw(SDL_Renderer *renderer);
    };
}