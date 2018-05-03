#pragma once

#include <string>

namespace Coronet
{
    void QuitSDL();
    void ThrowSDLException(std::string method, std::string message = "");
    void ThrowIMGException(std::string method, std::string message = "");
    void ThrowTTFException(std::string method, std::string message = "");
    void ThrowPHYSFSException(std::string method, std::string message = "");
    std::string Demangle(const char *name);
}