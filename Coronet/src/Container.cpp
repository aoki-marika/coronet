#include "Container.hpp"

namespace Coronet
{
    Container::Container() : Drawable()
    {
    }

    Container::~Container()
    {
    }

    void Container::Inject(DependencyManager &dependencies, bool callComplete)
    {
        if (State == DrawableLoadState::Unloaded)
        {
            this->dependencies = dependencies;
            Drawable::Inject(dependencies, false);

            for (auto &c : children)
            {
                //
                // this is required for children that are added in the ctor, as
                // shared_from_this, and in turn weak_from_this, cannot get a
                // pointer in the ctor, leaving the parent as null
                //
                c->Parent = weak_from_this();
                c->Inject(dependencies);
            }

            if (callComplete)
                LoadComplete();
        }
    }

    void Container::Add(const std::shared_ptr<Drawable> &drawable)
    {
        if (!drawable->Parent.expired())
            throw std::invalid_argument("Cannot add a Drawable to a Container when it is already in one.");

        children.push_back(drawable);
        drawable->Parent = weak_from_this();

        // dont bother if children are being added without dependencies injected,
        // they will get injected when this drawable is added to the scene
        if (State == DrawableLoadState::Loaded)
            drawable->Inject(dependencies);
    }

    void Container::Remove(const std::shared_ptr<Drawable> &drawable)
    {
        if (std::find(children.begin(), children.end(), drawable) != children.end())
            throw std::invalid_argument("Cannot remove a Drawable from a Container it is not in.");

        children.erase(std::remove(children.begin(), children.end(), drawable), children.end());
        drawable->Parent.reset();
    }

    void Container::Update()
    {
        Drawable::Update();

        for (auto &c : children)
            c->Update();
    }

    void Container::Draw(SDL_Renderer *renderer)
    {
        Drawable::Draw(renderer);

        for (auto &c : children)
            c->Draw(renderer);
    }
}