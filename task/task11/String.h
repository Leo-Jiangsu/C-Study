#ifndef STRING_H
#define STRING_H

#include <iostream>


class String
{
public:
    class Proxy;
    //operator output/input
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend std::istream &operator>>(std::istream &, String &);
    friend std::ostream &operator<<(std::ostream &, const Proxy &);
public:
    //Constructor
    String()
        : size_(0),
        capacity_(0),
        pstr_(new char[5]() + sizeof(int)) {}
    String(const char *);
    String(const String &);
    //Destructor
    ~String() { release_pstr(); }

    //overload 
    String &operator=(const char *);
    String &operator=(const String &);
    String &operator+=(const char *);
    String &operator+=(const String &);
    Proxy operator[](size_t index);
    char operator[](size_t index) const;

    const char *c_str() const { return pstr_; }

    //Refcount Function
    void refcount_init() { *(int *)(pstr_ - (sizeof(int))) = 1; }
    void refcount_increase() { *(int *)(pstr_ - sizeof(int)) += 1;  }
    void refcount_decrease() { *(int *)(pstr_ - sizeof(int)) -= 1;  }
    int refcount() const { return *(int *)(pstr_ - sizeof(int));  }
    void release_pstr();


    class Proxy
    {
        friend std::ostream &operator<<(std::ostream &, const Proxy &);
    public:
        Proxy(String &str, size_t index) : str_(str), index_(index) {}
        ~Proxy() {}
        Proxy &operator=(char ch);

    private:
        String &str_;
        size_t index_;
    };
private:
    size_t size_;
    size_t capacity_;
    //capacity available to write(excluding '\0')
    //every time new size = sizeof(int) + capacity_ + 1('\0') byte
    
    char *pstr_;
    //[Refcount][pstr]
    //[-4      ][0   ]

};

#endif

