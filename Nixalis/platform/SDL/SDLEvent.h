#ifndef SDLEVENTS_H
#define SDLEVENTS_H

#include <SDL3/SDL_events.h>

#include "nixalis/Event/Event.h"


namespace nixalis
{
    class SDLEvent : public Event
    {
        bool HandleEvent(const SDL_Event& e);
    };
}

#endif //SDLEVENTS_H