#pragma once
#include "Event.h"
#include "Events.h"
#include "Node.h"
#include "Listener.h"

#define DEFAULT_PRIO    50

#define KEY_UP			0
#define KEY_DOWN		1

namespace EventManager
{
    // Add a listener with the given priority
    void add(Listener* listener, int e, int priority);
    
    // Add a listener with the default priority
    void add(Listener* listener, int e);

    // Remove the given listener from the listeners queue
    void remove(Listener* listener, int e);

    // Pass the given event along to the appropriate queue
    void handle(int e);
    void handle(Event e);

    extern Node* lists[NUM_EVENTS];
}