#include "TestBrowserItem.hpp"
#include "AssetStore.hpp"
#include "Utilities.hpp"
#include "Text.hpp"

namespace Coronet
{
    TestBrowserItem::TestBrowserItem(std::type_index type) : type(type)
    {
    }

    void TestBrowserItem::Load(DependencyManager &dependencies)
    {
        Container::Load(dependencies);

        auto font = dependencies.Get<AssetStore>()->GetTTF("HelvetiPixel.ttf", 15);
        Add(std::make_shared<Text>(font, Demangle(type.name())));
    }
}