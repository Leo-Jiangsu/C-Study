#include "Singleton.h"

void test()
{
    Singleton *p = &Singleton::GetInstance();
    p = &Singleton::GetInstance();
    p = &Singleton::GetInstance();
    p = &Singleton::GetInstance();

}

int main()
{
    test();
    return 0;
}

