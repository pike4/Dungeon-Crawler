#pragma once
#include <vector>

struct Event
{
    int opcode;
    std::vector<int> args;

    Event(int op)
		: opcode(op)
    {
        
    }

	Event(int op, std::vector<int> a) : Event(op)
	{
		args = a;
	}
};