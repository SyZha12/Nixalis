#include "LinuxWindow.h"

#include "nixalis/Core/Keys.h"

#define WINDOWRENDERER 1

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

    void LinuxWindow::HandleEvent(SDL_Event& event)
    {
        if(event.window.windowID == m_Properties.windowID)
        {
            INFO("SDL_Event Window 1 {} & Window {}", event.type, event.window.windowID);
        }
    }

    void LinuxWindow::Init(const WindowProperties& windowProperties)
    {
        m_Properties.title = windowProperties.title;
        m_Properties.width = windowProperties.width;
        m_Properties.height = windowProperties.height;

        if(WINDOWRENDERER)
        {
            SDL_CreateWindowAndRenderer(
                windowProperties.title.c_str(),
                windowProperties.width,
                windowProperties.height,
                SDL_WINDOW_VULKAN |
                SDL_WINDOW_RESIZABLE,
                &m_Properties.window,
                &m_Properties.renderer
                );
        }
        else
        {
            m_Properties.window = SDL_CreateWindow(
            windowProperties.title.c_str(),
            windowProperties.width,
            windowProperties.height,
            SDL_WINDOW_VULKAN |
                 SDL_WINDOW_RESIZABLE
        );
        }

        m_Properties.windowID = SDL_GetWindowID(m_Properties.window);
        m_Properties.isClosed = false;

        if(SDL_Init(SDL_INIT_VIDEO))
            INFO("SDL initialized");
    }

    void LinuxWindow::Update()
    {
        SDL_SetRenderDrawColor(m_Properties.renderer, 255, 0, 0, 255);
        SDL_RenderClear(m_Properties.renderer);
        SDL_RenderPresent(m_Properties.renderer);
    }

    void LinuxWindow::Close()
    {
        if(m_Properties.renderer == nullptr)
            SDL_DestroyRenderer(m_Properties.renderer);
        if(m_Properties.window == nullptr)
            SDL_DestroyWindow(m_Properties.window);

        SDL_Quit();
    }

    unsigned int LinuxWindow::GetWidth() const
    {
        return m_Properties.width;
    }

    unsigned int LinuxWindow::GetHeight() const
    {
        return m_Properties.height;
    }

    int LinuxWindow::GetWindowID() const
    {
        return m_Properties.windowID;
    }

    void LinuxWindow::SetWidth(const unsigned int width)
    {
        m_Properties.width = width;
    }

    void LinuxWindow::SetHeight(const unsigned int height)
    {
        m_Properties.height = height;
    }

    bool LinuxWindow::IsClosed() const
    {
        return m_Properties.isClosed;
    }
}
