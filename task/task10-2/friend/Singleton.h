#ifndef SINGLETON_H_
#define SINGLETON_H_
#include <iostream>

class Singleton
{
    friend class AutoRelease;
public:
    static Singleton *GetInstance();

private:
    Singleton();
    ~Singleton();
    static Singleton *pinstance_;
};


class AutoRelease
{
public:
    AutoRelease() {}
    ~AutoRelease();
};

#endif

