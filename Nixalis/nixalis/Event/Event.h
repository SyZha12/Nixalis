#ifndef EVENT_H
#define EVENT_H

namespace nixalis
{
    class Event
    {
    public:
        Event();
        virtual bool HandleEvent() = 0;
    };
}

#endif //EVENT_H
