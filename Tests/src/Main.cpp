#include <iostream>

#include <Coronet/GameHost.hpp>

#include "TestsGame.hpp"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        auto host = std::make_shared<Coronet::GameHost>("Tests");
        auto game = std::make_shared<Tests::TestsGame>(argv[1]);

        host->Run(game);

        return 0;
    }

    std::cout << "Please specify a test to run using the first argument." << std::endl;
    return 1;
}