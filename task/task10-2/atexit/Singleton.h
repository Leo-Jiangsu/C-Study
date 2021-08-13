#ifndef SINGLETON_H_
#define SINGLETON_H_

class Singleton
{
public:
    static Singleton *GetInstance();

    static void Destory()
    {
        if(pinstance_)
        {
            delete pinstance_;
        }
    }

private:
    Singleton();
    ~Singleton();
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

    static Singleton *pinstance_;

};

#endif

