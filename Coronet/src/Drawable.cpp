#include "Drawable.hpp"

namespace Coronet
{
    Vector2 Drawable::GetDrawPosition(bool includeCamera)
    {
        Vector2 position = Position;

        if (includeCamera && Space == DrawablePositionSpace::World)
            position = position - camera->Position;

        if (!Parent.expired())
            position = Parent.lock()->GetDrawPosition() + position;

        return position;
    }

    Vector2 Drawable::GetDrawSize()
    {
        return { 0, 0 };
    }

    Visibility Drawable::GetVisibility()
    {
        if (Visibility != Visibility::Hidden && !Parent.expired())
            return Parent.lock()->GetVisibility();

        return Visibility;
    }

    Flip Drawable::GetFlip()
    {
        if (!Parent.expired())
        {
            auto parentFlip = Parent.lock()->GetFlip();

            if (parentFlip != Flip::None)
            {
                if (Flip == Flip::None)
                    return parentFlip;

                auto horizontal = Flip::None;
                auto vertical = Flip::None;

                if (parentFlip & Flip::Horizontal && Flip & Flip::Horizontal)
                    horizontal = Flip::None;
                else if (Flip & Flip::Horizontal)
                    horizontal = Flip::Horizontal;

                if (parentFlip & Flip::Vertical && Flip & Flip::Vertical)
                    vertical = Flip::None;
                else if (Flip & Flip::Vertical)
                    vertical = Flip::Vertical;

                return horizontal | vertical;
            }
        }

        return Flip;
    }

    bool Drawable::IsVisible()
    {
        if (GetVisibility() == Visibility::Hidden)
            return false;

        Vector2 p = GetDrawPosition(true);
        Vector2 s = GetDrawSize();
        SDL_Rect v = camera->GetViewport();

        // ignore camera position if we are in screen space
        if (Space == DrawablePositionSpace::Screen)
        {
            v.x = 0;
            v.y = 0;
        }

        bool offScreen = p.x >= v.w || p.x + s.x <= 0 ||
                         p.y >= v.h || p.y + s.y <= 0;

        return !offScreen;
    }

    void Drawable::Load(DependencyManager &dependencies)
    {
        clock = dependencies.Get<GameClock>();
        camera = dependencies.Get<Camera>();
    }

    void Drawable::LoadComplete()
    {
    }

    void Drawable::Inject(DependencyManager &dependencies, bool callComplete)
    {
        if (State == DrawableLoadState::Unloaded)
        {
            Load(dependencies);
            State = DrawableLoadState::Loaded;

            if (callComplete)
                LoadComplete();
        }
    }

    bool Drawable::OnKeyDown(SDL_Event event)
    {
        return false;
    }

    bool Drawable::OnKeyUp(SDL_Event event)
    {
        return false;
    }

    void Drawable::Update()
    {
        UpdateTransforms(clock);
    }

    void Drawable::Draw(SDL_Renderer *renderer)
    {
    }
}