#pragma once
#include "Event.h"

class Listener
{
public:
    virtual void handle(Event e) = 0;
};


// Prints the opcode on event receive, used for testing
class Printer : public Listener
{
public:
    virtual void handle(Event e)
    {
        printf("Received event: %d\n", e.opcode);
    }
};