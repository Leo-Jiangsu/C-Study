#include "Singleton.h"

Singleton &Singleton::GetInstance()
{
    static Singleton instance_;
    return instance_;
}
/* void Singleton::Destroy() */
/* { */
    /* delete ; */
/* } */


