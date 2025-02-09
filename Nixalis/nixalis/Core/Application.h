#ifndef APPLICATION_H
#define APPLICATION_H

#include <nixalis_export.h>

namespace Nixalis
{
    class NIXALIS_EXPORT Application
    {
    public:
        Application();
        virtual ~Application() = default;
    };

    extern Application* CreateApplication();
}


#endif //APPLICATION_H
