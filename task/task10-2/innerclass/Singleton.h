#ifndef SINGLETON_H_
#define SINGLETON_H_

class Singleton
{
public:
    static Singleton *GetInstance();

private:
    Singleton();
    ~Singleton();
    class AutoRelease
    {
    public:
        AutoRelease() {}
        ~AutoRelease()
        {
            if(pinstance_)
            {
                delete pinstance_;
                pinstance_ = nullptr;
            }
        }
    };

    static Singleton *pinstance_;
    /* static const int i = 5; */
    static AutoRelease au_;
};

#endif

