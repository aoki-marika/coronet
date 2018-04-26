#include <Coronet/GameHost.hpp>
#include <Coronet/Logging.hpp>

#include "TestsGame.hpp"

using Coronet::Logger;
using Coronet::LogLevel;

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        auto host = std::make_shared<Coronet::GameHost>("Tests", std::make_shared<Coronet::Metrics>(8, 8, 2, 2, 20, 18));
        auto game = std::make_shared<Tests::TestsGame>(argv[1]);

        host->Run(game);

        return 0;
    }

    Log(LogLevel::Error) << "No test specified, please specify one with the first argument.";
    return 1;
}