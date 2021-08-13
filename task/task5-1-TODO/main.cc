#include "Singleton.h"

void test()
{
    Singleton *p = Singleton::GetInstance();
    p = Singleton::GetInstance();
    p = Singleton::GetInstance();
    p = Singleton::GetInstance();

    Singleton::Destroy();
    Singleton::Destroy();
    Singleton::Destroy();
}

int main()
{
    test();
    return 0;
}

