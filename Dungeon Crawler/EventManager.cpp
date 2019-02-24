#include "EventManager.h"
#include "Node.h"

namespace EventManager
{
    void add(Listener* listener, int e, int priority)
    {
        if (e < 0 || e >= NUM_EVENTS) {
            printf("Error, invalid event opcode");
        }

        else if (lists[e] == NULL)
        {
            lists[e] = new Node(NULL, listener, priority);
        }

        else if (lists[e] != NULL)
        {
            if (priority >= lists[e]->priority)
            {
                lists[e] = new Node(lists[e], listener, priority);
            }
        }

        else
        {
            Node* cur = lists[e];
            while (cur->next != NULL)
            {
                if (priority >= cur->next->priority)
                {
                    cur->next = new Node(cur->next, listener, priority);
                    break;
                }
            }
        }
    }

    void add(Listener* listener, int e)
    {
        add(listener, e, DEFAULT_PRIO);
    }

    void remove(Listener* listener, int e)
    {
        if (e < 0 || e >= NUM_EVENTS) {
            printf("Error, invalid event opcode");
        }

        else if (lists[e] == NULL) {
            printf("Error, listener not registered for event");
        }

        else if (lists[e]->listener == listener)
        {
            Node* temp = lists[e];
            lists[e] = lists[e]->next;

            delete temp;
        }

        else
        {
            Node* cur = lists[e];
            while (cur->next != NULL)
            {
                if (cur->next->listener == listener)
                {
                    Node* temp = cur->next;
                    cur->next = cur->next->next;

                    delete temp;
                    return;
                }

                cur = cur->next;
            }

            printf("Error, listener not registered for event");
        }
    }

    void handle(int e)
    {
        Event newE(e);
        handle(newE);
    }

    void handle(Event e)
    {
        // Check invalid opcode
        if (e.opcode < 0 || e.opcode >= NUM_EVENTS) {
            printf("Error, invalid event opcode");
        }

        // Send to each listener in the given queue
        else
        {
            Node* cur = lists[e.opcode];

            while (cur != NULL)
            {
                cur->listener->handle(e);
                cur = cur->next;
            }
        }
    }

    Node* lists[NUM_EVENTS];
}