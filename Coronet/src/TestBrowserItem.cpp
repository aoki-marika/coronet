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

        auto text = std::make_shared<Text>(dependencies.Get<AssetStore>()->GetTTF("HelvetiPixel.ttf", 15));
        text->SetText(Demangle(type.name()));

        Add(text);
    }
}