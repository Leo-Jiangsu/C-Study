#include <iostream>
#include "stack.h"

void Stack::Push(int data)
    {
        if(!full())
        {
            ++top_index_;
            element_[top_index_] = data;
        }
    }

void Stack::Pop()
{
    if(!empty())
    {
        --top_index_;
    }
}

using std::cout;
using std::endl;
using std::cin;

