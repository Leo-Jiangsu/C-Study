#include "Singleton.h"
#include <iostream>

using std::cout;
using std::endl;

void TestAtexit()
{
    Singleton::GetInstance();
    Singleton::GetInstance();
    Singleton::GetInstance();
}

void TestExit()
{
    cout << "TestExit" << endl;
}

void TestAtexit2()
{
    atexit(TestExit);
    atexit(TestExit);
    atexit(TestExit);

}


int main()
{
    TestAtexit2();
    return 0;
}

