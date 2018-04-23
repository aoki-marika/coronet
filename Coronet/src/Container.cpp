#include "Container.hpp"

namespace Coronet
{
    Container::Container() : Drawable()
    {
    }

    Container::~Container()
    {
    }

    void Container::Add(const std::shared_ptr<Drawable> &drawable)
    {
        if (!drawable->Parent.expired())
            throw std::invalid_argument("Cannot add a Drawable to a Container when it is already in one.");

        drawable->Parent = weak_from_this();
        children.push_back(drawable);
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
}