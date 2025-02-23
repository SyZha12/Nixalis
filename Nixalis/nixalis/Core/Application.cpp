#include "Application.h"

// #include <iostream>

#include <imgui.h>

#include "nixalis/Core/Log.h"

namespace Nixalis
{
    Application::Application()
    {
        m_Window = Window::CreateWindow();
        // m_Window2 = Window::CreateWindow();
    }

    void Application::Run()
    {
        while(m_Running)
        {
            while(SDL_PollEvent(&m_Event) != 0)
            {
                if(m_Event.type == SDL_EVENT_QUIT)
                {
                    m_Running = false;
                    INFO("Quitting...");
                }

                m_Window->HandleEvent(m_Event);
            }

            // uint64_t time = SDL_GetTicks();
            // INFO("Time {}", time);
            m_Window->Update();
        }
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* layer)
    {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }
}
