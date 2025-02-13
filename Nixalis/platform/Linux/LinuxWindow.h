#ifndef LINUXWINDOW_H
#define LINUXWINDOW_H

#include <SDL3/SDL.h>

#include "nixalis/Core/Window.h"
#include "nixalis/Core/Log.h"


// template<typename OStream>
// OStream& operator<<(OStream &os, const Test& msg)
// {
//     fmt::format_to(std::ostream_iterator<char>(os), "{:04X}", msg.code);
//     return os;
// }

namespace Nixalis
{
    class LinuxWindow : public Window
    {
    public:
        LinuxWindow(const WindowProperties& windowProperties);
        virtual ~LinuxWindow();

        void HandleEvent(SDL_Event& event) override;
        void Update() override;

        unsigned int getWidth() const override;
        unsigned int getHeight() const override;
        bool isClosed() const override;
    private:
        void Init(const WindowProperties& windowProperties) override;
        void Close() override;

        struct Properties
        {
            std::string title;
            unsigned int width, height;

            SDL_Window* window;
            int windowID;

            bool isClosed;
        } m_Properties;
        // Properties m_Properties;

        SDL_Event m_Event;

    };
}


#endif //LINUXWINDOW_H
