#include "queue.h"


int queue::size()
{
    item* current = head;
    int numCount = 0;

    if(head == nullptr)
    {
        return 0;
    }

    numCount++;
    while(current->next != nullptr)
    {
        numCount++;
        current = current->next;
    }

    return numCount;
}

bool queue::empty()
{
    if(head == nullptr){return true;}
    else{return false;}
}

void queue::push(int number)
{
    item* current = head;
    item* newItem = new item;
    newItem->number = number;

    if(head == nullptr)
    {
        head = newItem;
        newItem->next = nullptr;
        return;
    }

    while(current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newItem;
    newItem->next = nullptr;
}

void queue::pop()
{
    if(head->next != nullptr)
    {
        item* holder = head->next;
        head = nullptr;
        head = holder;
    }
    else
    {
        head = nullptr;
    }    
}