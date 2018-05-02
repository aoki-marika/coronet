#include <Coronet/AssetStore.hpp>

#include "CoronetTestGame.hpp"

namespace Tests
{
    void CoronetTestGame::Load(Coronet::DependencyManager &dependencies)
    {
        TestGame::Load(dependencies);

        dependencies.Get<Coronet::AssetStore>()->Mount("Tests.assets.zip");
    }
}