#include "Singleton.h"
#include <iostream>

using std::cout;
using std::endl;

void TestFriendClass()
{
    AutoRelease ar;
    Singleton::GetInstance();
}

int main()
{
    TestFriendClass();
    return 0;
}

