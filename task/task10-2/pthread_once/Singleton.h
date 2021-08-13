#ifndef SINGLETON_H_ 
#define SINGLETON_H_ 
#include <pthread.h>

class Singleton
{
public:

    static void Init();

    static void Destory();

    static Singleton* GetInstance();

private:
    Singleton();
    ~Singleton();
    Singleton(const Singleton &) = delete; 
    Singleton &operator=(const Singleton &) = delete; 

    static Singleton *pinstance_;
    static pthread_once_t once_;
};

#endif

