#include "stack.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    Stack s;
    s.Push(10);
    s.Push(12);
    s.Push(14);
    cout << "top = " << s.top() << endl;
    s.Pop();
    cout << "top = " << s.top() << endl;
    return 0;
}

