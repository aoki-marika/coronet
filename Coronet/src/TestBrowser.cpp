#include <iostream>

#include "TestBrowser.hpp"
#include "Utilities.hpp"
#include "Text.hpp"

namespace Coronet
{
    TestBrowser::TestBrowser()
    {
        Space = DrawablePositionSpace::Screen;

        items = std::make_shared<Container>();
        font = std::make_shared<TTFFont>("HelvetiPixel.ttf", 15);
        arrow = std::make_shared<Sprite>(std::make_shared<Bitmap>("test-selection.png"));

        items->Position = { ITEM_HEIGHT, 0 };
        items->Add(arrow);

        Add(items);
        selectItem(selectedItem);
    }

    void TestBrowser::selectItem(int index)
    {
        if (testTypes.size() > 0)
        {
            arrow->Visibility = Visibility::Visible;
            arrow->Position = { -ITEM_HEIGHT, ITEM_HEIGHT * index };
        }
        else
            arrow->Visibility = Visibility::Hidden;
    }

    void TestBrowser::AddTest(std::type_index testType)
    {
        auto item = std::make_shared<Text>(font);
        item->SetText(Demangle(testType.name()));
        item->Position = { 0, ITEM_HEIGHT * static_cast<int>(testTypes.size()) };

        items->Add(item);
        testTypes.push_back(testType);
        selectItem(selectedItem);
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