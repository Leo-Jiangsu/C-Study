#ifndef BASE_H_
#define BASE_H_

class Base
{
    friend Base operator+(const Base &lhs, const Base &rhs);
public:
    Base(int data = 0) 
        : data_(data)
    {}
    ~Base() {}

    operator int () const
    {
        return data_;
    }

private:
    int data_;
};

#endif

