#include "Singleton.h"

Singleton *Singleton::GetInstance()
{
    if(!instance_)
    {
        instance_ = new Singleton();
    }
    return instance_;
}
void Singleton::Destroy()
{
    if(instance_)
    {
        delete instance_;
        instance_ = nullptr;
    }
}

Singleton *Singleton::instance_ = nullptr;

