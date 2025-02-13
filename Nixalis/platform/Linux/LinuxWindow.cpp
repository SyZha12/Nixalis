#include "LinuxWindow.h"

namespace Nixalis
{
    LinuxWindow::LinuxWindow(const WindowProperties& windowProperties)
    {
        Init(windowProperties);
    }

    LinuxWindow::~LinuxWindow()
    {
        Close();
    }

    void LinuxWindow::Init(const WindowProperties& windowProperties)
    {
        m_Properties.title = windowProperties.title;
        m_Properties.width = windowProperties.width;
        m_Properties.height = windowProperties.height;

        m_Properties.window = SDL_CreateWindow(
            windowProperties.title.c_str(),
            windowProperties.width,
            windowProperties.height,
            SDL_WINDOW_VULKAN |
                 SDL_WINDOW_RESIZABLE
        );
        m_Properties.windowID = SDL_GetWindowID(m_Properties.window);
        m_Properties.isClosed = false;

        if(SDL_Init(SDL_INIT_VIDEO))
            INFO("SDL initialized");
    }

    void LinuxWindow::HandleEvent(SDL_Event& event)
    {
        if(event.window.windowID == m_Properties.windowID)
        {
            switch(event.window.type)
            {
            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                m_Properties.isClosed = true;
                break;
            }
        }
    }

    void LinuxWindow::Update()
    {

    }

    void LinuxWindow::Close()
    {
        SDL_DestroyWindow(m_Properties.window);

        SDL_Quit();
    }

    unsigned int LinuxWindow::getWidth() const
    {
        return m_Properties.width;
    }

    unsigned int LinuxWindow::getHeight() const
    {
        return m_Properties.height;
    }

    bool LinuxWindow::isClosed() const
    {
        return m_Properties.isClosed;
    }
}
