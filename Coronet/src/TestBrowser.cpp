#include "TestBrowser.hpp"
#include "TestBrowserItem.hpp"
#include "Utilities.hpp"
#include "Text.hpp"
#include "Metrics.hpp"
#include "AssetStore.hpp"

namespace Coronet
{
    // todo: move into a base class so this logic can be shared
    // todo: dont create the text here, but have an item class

    TestBrowser::TestBrowser()
    {
        Space = DrawablePositionSpace::Screen;

        items = std::make_shared<Container>();
        items->Position = { TestBrowserItem::HEIGHT, 0 };

        Add(items);
    }

    void TestBrowser::Load(DependencyManager &dependencies)
    {
        Container::Load(dependencies);

        auto assets = dependencies.Get<AssetStore>();

        arrow = std::make_shared<Sprite>(assets->GetBitmap("test-selection.png"));

        items->Add(arrow);

        maximumItems = int(dependencies.Get<Metrics>()->GetScreenSize().y / 12);
        selectItem(selectedItem);
    }

    void TestBrowser::selectItem(int index)
    {
        if (testTypes.size() > 0)
        {
            arrow->Visibility = Visibility::Visible;
            arrow->Position = { -TestBrowserItem::HEIGHT, TestBrowserItem::HEIGHT * index };

            int upperVisible = firstVisibleItem + std::max(0, maximumItems - 1);

            if (index > upperVisible)
                firstVisibleItem = (index - maximumItems) + 1;
            else if (index < firstVisibleItem)
                firstVisibleItem = index;

            items->Position.y = -(TestBrowserItem::HEIGHT * firstVisibleItem);
        }
        else
            arrow->Visibility = Visibility::Hidden;
    }

    void TestBrowser::AddTest(std::type_index testType)
    {
        auto item = std::make_shared<TestBrowserItem>(testType);
        item->Position = { 0, TestBrowserItem::HEIGHT * static_cast<int>(testTypes.size()) };
        items->Add(item);

        testTypes.push_back(testType);
    }

    bool TestBrowser::OnKeyDown(SDL_Event event)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_UP:
                selectedItem--;
                break;
            case SDLK_DOWN:
                selectedItem++;
                break;
            case SDLK_RETURN:
                if (testTypes.size() > 0 && OnSelectTest != nullptr)
                    OnSelectTest(testTypes[selectedItem]);
                break;
            default:
                return Container::OnKeyDown(event);
        }

        if (selectedItem < 0)
            selectedItem = 0;
        else if (selectedItem >= testTypes.size())
            selectedItem = testTypes.size() - 1;

        selectItem(selectedItem);

        return true;
    }
}