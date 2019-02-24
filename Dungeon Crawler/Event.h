#pragma once
#include <vector>

struct Event
{
    int opcode;
    std::vector<int> args;

    Event(int op)
    {
        opcode = op;
    }
};