#include "Singleton.h"
#include <iostream>

using std::cout;
using std::endl;

Singleton *Singleton::GetInstance()
{
    if(!pinstance_)
    {
        pinstance_ = new Singleton();
    }
    return pinstance_;
}


Singleton::Singleton() { cout << "Constructor" << endl; }
Singleton::~Singleton() { cout << "Destructor" << endl; }


Singleton::AutoRelease Singleton::au_;
Singleton *Singleton::pinstance_ = nullptr;

