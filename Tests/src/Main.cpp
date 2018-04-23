#include <Coronet/GameHost.hpp>

int main(int argc, char *argv[])
{
    auto host = std::make_shared<Coronet::GameHost>();
    auto game = std::make_shared<Coronet::Game>();

    host->Run(game);

    return 0;
}