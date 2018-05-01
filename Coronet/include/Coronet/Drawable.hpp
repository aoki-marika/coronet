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

    enum class Flip
    {
        None = SDL_FLIP_NONE,
        Horizontal = SDL_FLIP_HORIZONTAL,
        Vertical = SDL_FLIP_VERTICAL
    };

    inline Flip operator|(Flip lhs, Flip rhs)
    {
        return static_cast<Flip>(static_cast<int>(lhs) | static_cast<int>(rhs));
    }

    inline bool operator&(Flip lhs, Flip rhs)
    {
        return static_cast<bool>(static_cast<int>(lhs) & static_cast<int>(rhs));
    }

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
            virtual DrawablePositionSpace GetSpace();
            virtual Visibility GetVisibility();
            virtual Flip GetFlip();

            virtual void Load(DependencyManager &dependencies);
            virtual void LoadComplete();

        public:
            std::weak_ptr<Drawable> Parent;
            Vector2 Position = { 0, 0 };
            DrawablePositionSpace Space = DrawablePositionSpace::World;
            Visibility Visibility = Visibility::Visible;
            Flip Flip = Flip::None;

            virtual bool IsVisible();

            // todo: dont like callComplete
            virtual void Inject(DependencyManager &dependencies, bool callComplete = true);
            virtual bool TriggerKeyDown(SDL_Event event);
            virtual bool TriggerKeyUp(SDL_Event event);
            virtual bool OnKeyDown(SDL_Event event);
            virtual bool OnKeyUp(SDL_Event event);
            virtual void Hide();
            virtual void Show();
            virtual void AddRelativeTransform(double startValue, double endValue, double delay, double duration, Easing easing, std::function<void(double)> callback, std::function<void()> onFinished = nullptr);
            virtual void Update();
            virtual void Draw(SDL_Renderer *renderer);
    };
}