#include "Queue.h"
#include <iostream>

void Queue::Push(int data)
{
    if(!full())
    {
        element_[tail_] = data;
        tail_ = (tail_ + 1) % (size_ + 1);
    }
}

void Queue::Pop()
{
    if(!empty())
    {
        head_ = (head_ + 1) % (size_ + 1);
    }
}


