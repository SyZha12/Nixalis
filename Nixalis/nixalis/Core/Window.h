#ifndef WINDOW_H
#define WINDOW_H

#include <memory>
#include <string>

#include <SDL3/SDL.h>

namespace Nixalis
{
    struct WindowProperties
    {
        std::string title;
        unsigned int width, height;
        bool isClosed;

        WindowProperties( const std::string& title = "Nixalis", const unsigned int width = 640, const unsigned int height = 480 )
            : title(title), width(width), height(height), isClosed(false) {}
    };
    class Window
    {
    public:
        // New windows are created with this static function
        static std::unique_ptr<Window> CreateWindow(const WindowProperties& windowProperties = WindowProperties());
        // All virtual functions
        virtual ~Window() = default;

        virtual void Init(const WindowProperties& windowProperties) = 0;
        virtual void HandleEvent(SDL_Event& event) = 0;
        virtual void Update() = 0;
        virtual void Close() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;
        virtual int GetWindowID() const = 0;

        virtual void SetWidth(unsigned int width) = 0;
        virtual void SetHeight(unsigned int height) = 0;

        virtual bool IsClosed() const = 0;
    private:
    };
}



#endif //WINDOW_H
