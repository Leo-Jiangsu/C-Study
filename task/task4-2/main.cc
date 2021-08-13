#include "List.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void test_empty()
{
    List L;
    L.display();
    L.pop_back();
    L.display();
    L.pop_front();
    L.display();
    cout << L.find(10) << endl;
    L.erase(10);
    L.display();
}

void test_push()
{
    List L;
    L.display();
    L.push_back(1);
    L.display();
    L.push_back(2);
    L.display();
    L.push_back(3);
    L.display();
    L.push_back(4);
    L.display();
    L.push_back(5);
    L.display();
    L.push_front(6);
    L.display();
    L.push_front(7);
    L.display();
    L.push_front(8);
    L.display();
    L.push_front(9);
    L.display();
    L.push_front(10);
    L.display();
}

void test_pop()
{
    List L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    L.push_back(5);
    L.push_front(6);
    L.push_front(7);
    L.push_front(8);
    L.push_front(9);
    L.push_front(10);
    L.display();
    L.pop_back();
    L.display();
    L.pop_back();
    L.display();
    L.pop_back();
    L.display();
    L.pop_front();
    L.display();
    L.pop_front();
    L.display();
    L.pop_front();
    L.display();
}

void test_pop2()
{
    List L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    L.push_back(5);
    L.display();
    L.pop_front();
    L.display();
    L.pop_front();
    L.display();
    L.pop_front();
    L.display();
    L.pop_front();
    L.display();
    L.pop_front();
    L.display();
    L.pop_front();
    L.display();
}

void test_pop3()
{
    List L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    L.push_back(5);
    L.display();
    L.pop_back();
    L.display();
    L.pop_back();
    L.display();
    L.pop_back();
    L.display();
    L.pop_back();
    L.display();
    L.pop_back();
    L.display();
    L.pop_back();
    L.display();
}
void test_erase()
{
    List L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    L.push_back(5);
    L.display();
    L.erase(2);
    L.display();
    L.erase(2);
    L.display();

    L.erase(4);
    L.display();
    L.erase(4);
    L.display();

    L.erase(1);
    L.display();
    L.erase(3);
    L.display();
    L.erase(5);
    L.display();
    L.erase(0);
    L.display();
}

void test_insert()
{
    List L;
    L.insert(0, 1);
    L.display();
    L.insert(0, 2);
    L.display();
    L.insert(0, 3);
    L.display();
    L.insert(0, 4);
    L.display();
    L.insert(0, 5);
    L.display();

    L.insert(10, 1);
    L.display();
    L.insert(10, 1);
    L.display();

    L.insert(5, 1);
    L.display();
    L.insert(6, 1);
    L.display();


    L.insert(3, 11);
    L.display();

    L.insert(5, 22);
    L.display();

}
void test_find()
{
    List L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    L.push_back(5);
    L.display();

    cout << L.find(0) << endl;

    cout << L.find(3) << endl;

    cout << L.find(-1) << endl;

    cout << L.find(-5) << endl;

    cout << L.find(5) << endl;

}

int main()
{
    /* test_empty(); */
    /* test_push(); */
    /* test_pop(); */
    /* test_pop2(); */
    /* test_pop3(); */
    /* test_erase(); */
    /* test_insert(); */
    test_find();
    
    return 0;
}

