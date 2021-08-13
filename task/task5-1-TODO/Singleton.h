#ifndef SINGLETON_H_
#define SINGLETON_H_
#include <iostream>

class Singleton
{
public:
    static Singleton *GetInstance();
    static void Destroy();

private:
    Singleton() { std::cout << "Singleton()" << std::endl; }
    ~Singleton() { std::cout << "~Singleton()" << std::endl; }
    static Singleton *instance_;

};


#endif

