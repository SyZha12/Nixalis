#include "Window.h"

#include "platform/Linux/LinuxWindow.h"

namespace Nixalis
{
    std::unique_ptr<Window> Window::CreateWindow(const WindowProperties& windowProperties)
    {
        return std::make_unique<LinuxWindow>(windowProperties);
    }

}
