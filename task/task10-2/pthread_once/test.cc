#include "Singleton.h"
#include <iostream>

using std::cout;
using std::endl;

void TestThreadOnce()
{
    Singleton::GetInstance();
    Singleton::GetInstance();
    Singleton::GetInstance();
}

int main()
{
    TestThreadOnce();
    return 0;
}

