#include "Singleton.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void TestInnerClass()
{
    Singleton::GetInstance();
}



int main()
{
    TestInnerClass();
    return 0;
}

