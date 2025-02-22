#include "Application.h"

// #include <iostream>

#include "nixalis/Core/Log.h"
#include "vendor/imgui/imgui.h"

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
                // SDL_EVENT_WINDOW_MOVED = 517
                // SDL_EVENT_WINDOW_RESIZED = 518
                // After resizing we get 516, 517, 518, 519, 533
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
}
