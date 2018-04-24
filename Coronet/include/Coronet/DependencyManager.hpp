#pragma once

#include <sstream>
#include <map>
#include <typeindex>

#include "Utilities.hpp"

namespace Coronet
{
    class DependencyManager
    {
        private:
            std::map<std::type_index, std::weak_ptr<void>> dependencies;

        public:
            template<typename T> void Register(const std::weak_ptr<T> &dependency)
            {
                auto find = dependencies.find(typeid(T));

                if (find != dependencies.end())
                {
                    std::stringstream message;
                    message << "Cannot register multiple dependencies for type <" << Demangle(typeid(T).name()) << ">.";
                    throw std::invalid_argument(message.str());
                }
                else
                    dependencies[typeid(T)] = dependency;
            }

            template<typename T> std::shared_ptr<T> Get()
            {
                auto find = dependencies.find(typeid(T));

                if (find != dependencies.end())
                    return std::static_pointer_cast<T>(dependencies.at(typeid(T)).lock());
                else
                {
                    std::stringstream message;
                    message << "Dependency for type <" << Demangle(typeid(T).name()) << "> is not registered.";
                    throw std::invalid_argument(message.str());
                }
            }
    };
}