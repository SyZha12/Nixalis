#ifndef LINUXWINDOW_H
#define LINUXWINDOW_H

#include <SDL3/SDL.h>

#include "nixalis/Core/Keys.h"
#include "nixalis/Core/Window.h"
#include "nixalis/Core/Log.h"


// template<typename OStream>
// OStream& operator<<(OStream &os, const Nixalis::KeyCode msg)
// {
//     fmt::format_to(std::ostream_iterator<char>(os), "{:04X}", msg);
//     return os;
// }


// auto format_as(Nixalis::Keys::KeyCode Key) { return fmt::underlying(Key); }

namespace Nixalis
{
    class LinuxWindow : public Window
    {
    public:
        LinuxWindow(const WindowProperties& windowProperties);
        virtual ~LinuxWindow();

        void HandleEvent(SDL_Event& event) override;
        void Update() override;

        unsigned int GetWidth() const override;
        unsigned int GetHeight() const override;
        int GetWindowID() const override;

        void SetWidth(unsigned int width) override;
        void SetHeight(unsigned int height) override;

        bool IsClosed() const override;
    private:
        void Init(const WindowProperties& windowProperties) override;
        void Close() override;

        struct Properties
        {
            std::string title;
            unsigned int width, height;

            SDL_Window* window;
            SDL_Renderer* renderer;
            int windowID;

            bool isClosed;
        } m_Properties;

        SDL_Event m_Event;

    };
}


#endif //LINUXWINDOW_H
