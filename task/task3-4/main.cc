#include "Queue.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    Queue q(5);
    q.Push(10);
    q.Push(12);
    q.Push(14);
    /* cout << "Head of Queue: " << q.get_head() << endl; */
    /* cout << "Tail of Queue: " << q.get_tail() << endl; */
    /* q.Pop(); */
    /* cout << "Head of Queue: " << q.get_head() << endl; */
    /* cout << "Tail of Queue: " << q.get_tail() << endl; */
    q.Push(16);
    q.Push(18);
    /* q.Push(20); */
    cout << "Head of Queue: " << q.get_head() << endl;
    cout << "Tail of Queue: " << q.get_tail() << endl;

    return 0;
}

