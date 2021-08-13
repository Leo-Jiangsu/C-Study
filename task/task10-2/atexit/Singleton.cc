#include "Singleton.h"
#include <iostream>

using std::cout;
using std::endl;

Singleton::Singleton()
{
    cout << "Constructor" << endl;
}
Singleton::~Singleton()
{
    cout << "Destructor" << endl;
}
Singleton *Singleton::GetInstance()
{
    if(!pinstance_)
    {
        pinstance_ = new Singleton();
        atexit(Destory);
    }
    return pinstance_;
}

Singleton *Singleton::pinstance_ = GetInstance();
