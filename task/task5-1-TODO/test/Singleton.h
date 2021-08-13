#ifndef SINGLETON_H_
#define SINGLETON_H_
#include <iostream>

class Singleton
{
public:
    static Singleton &GetInstance();
    /* static void Destroy(); */
    ~Singleton() { std::cout << "~Singleton()" << std::endl; }

private:
    Singleton() { std::cout << "Singleton()" << std::endl; }
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
};


#endif

