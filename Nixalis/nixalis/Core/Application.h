#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL3/SDL.h>

#include <nixalis_export.h>

#include "LayerStack.h"
#include "nixalis/Core/Window.h"

namespace Nixalis
{
    class NIXALIS_EXPORT Application
    {
    public:
        Application();
        virtual ~Application() = default;

        void Run();
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
    private:
        bool m_Running = true;

        std::unique_ptr<Window> m_Window;
        std::unique_ptr<Window> m_Window2;
        SDL_Event m_Event;
        LayerStack m_LayerStack;
    };

    extern Application* CreateApplication();
}


#endif //APPLICATION_H
