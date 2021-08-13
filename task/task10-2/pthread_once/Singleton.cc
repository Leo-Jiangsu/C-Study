#include <pthread.h>
#include <iostream>
#include "Singleton.h"

using std::cout;
using std::endl;

void Singleton::Init()
{
    atexit(Destory);
    pinstance_ = new Singleton();
}

Singleton* Singleton::GetInstance()
{
    pthread_once(&once_, Init);
    return pinstance_;
}

void Singleton::Destory()
{
    if(pinstance_)
    {
        delete pinstance_;
        pinstance_ = nullptr;
    }
}

Singleton::Singleton()
{
    cout << "Constructor" << endl;
}
Singleton::~Singleton()
{
    cout << "Destructor" << endl;
}

Singleton *Singleton::pinstance_ = nullptr;
pthread_once_t Singleton::once_ = PTHREAD_ONCE_INIT;
