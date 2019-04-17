#pragma once

class item{
    public:
        int number;
        item* next;
        friend class queue;
};