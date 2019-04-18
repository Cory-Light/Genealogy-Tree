#pragma once
#include "item.h"

class queue
{
    public:
        int size();
        bool empty();
        void push(int number);
        void pop();
        int front();

    private:
        item* head = nullptr;

};