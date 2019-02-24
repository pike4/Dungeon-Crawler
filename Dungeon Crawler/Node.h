#pragma once
#include "Listener.h"

struct Node
{
    Node* next;
    Listener* listener;
    int priority;

    Node(Node* n, Listener* l, int p)
    {
        next = n;
        listener = l;
        priority = p;
    }
};