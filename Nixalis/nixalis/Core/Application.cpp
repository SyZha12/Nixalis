#include <nixalis/Core/Application.h>
#include <iostream>

namespace Nixalis
{
    Application::Application()
    {

    }

    void Application::Hello() const
    {
        std::cout << "Hello World!\n";
    }
}