#include "Application.h"

#include "nixalis/Core/Log.h"


namespace Nixalis
{
    Application::Application()
    {
        m_Window = Window::CreateWindow();
    }

    void Application::Run()
    {
        while(m_Running)
        {
            while(SDL_PollEvent(&m_Event))
            {
                INFO("Event - {}", m_Event.type);
                switch(m_Event.type)
                {
                case SDL_EVENT_QUIT:
                    m_Running = false;
                    INFO("Window closed");
                    break;
                }

                m_Window->HandleEvent(m_Event);
            }
        }
    }
}
