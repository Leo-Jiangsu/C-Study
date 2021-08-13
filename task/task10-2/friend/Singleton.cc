#include "Singleton.h"
#include <iostream>

using std::cout;
using std::endl;

Singleton::Singleton() { cout << "Singleton()" << endl; }
Singleton::~Singleton() { cout << "~Singleton()" << endl; }

Singleton *Singleton::GetInstance()
{
    if(!pinstance_)
    {
        pinstance_ = new Singleton();
    }
    return pinstance_;
}


AutoRelease::~AutoRelease()
{
    if(Singleton::pinstance_)
    {
        delete Singleton::pinstance_; 
        Singleton::pinstance_ = nullptr;
    }
}


Singleton *Singleton::pinstance_ = nullptr;

