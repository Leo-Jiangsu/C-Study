#include "String.h"
#include <string.h>

using std::cout;
using std::endl;
using std::cin;

//Constructor
String::String(const char *pstr)
    : size_(strlen(pstr)),
      capacity_(size_),
      pstr_(new char[sizeof(int) + capacity_ + 1]() 
            + sizeof(int))
{
    refcount_init();
    strcpy(pstr_, pstr);
}
String::String(const String &str)
    : size_(str.size_), 
      capacity_(str.capacity_),
      pstr_(str.pstr_ - sizeof(int))
{
    pstr_ += sizeof(int);
    refcount_increase();
}


//overload 
String &String::operator=(const char *pstr)
{
    release_pstr();
    size_ = strlen(pstr);
    capacity_ = size_;
    pstr_ = new char[sizeof(int) + capacity_ + 1]() + sizeof(int);
    refcount_init();
    strcpy(pstr_, pstr);
    return *this;
}

String &String::operator=(const String &str)
{
    if(this != &str)
    {
        release_pstr();
        size_ = str.size_;
        capacity_ = str.capacity_;
        pstr_ = str.pstr_;
        refcount_increase();
    }
    return *this;
}

String &String::operator+=(const char *pstr)
{
    size_ += strlen(pstr);
    if(size_ > capacity_)
    {
        capacity_ *= 2;
    }

    char *temp= new char[sizeof(int) + capacity_ + 1]() + sizeof(int);
    strcpy(temp, pstr_);
    strcat(temp, pstr);
    release_pstr();
    pstr_ = temp;
    refcount_init();
    return *this;
}

String &String::operator+=(const String &str)
{
    size_ += strlen(str.pstr_);
    if(size_ > capacity_)
    {
        capacity_ *= 2;
    }
    
    char *temp= new char[sizeof(int) + capacity_ + 1]() + sizeof(int);
    strcpy(temp, pstr_);
    strcat(temp, str.pstr_);
    release_pstr();
    pstr_ = temp;
    refcount_init();

    return *this;

}

String::Proxy String::operator[](size_t index)
{
    return Proxy(*this, index);
#if 0
    if(index < size_)
    {
        char *temp = new char[sizeof(int) + capacity_ + 1]() + sizeof(int);
        strcpy(temp, pstr_);
        release_pstr();
        pstr_ = temp;
        refcount_init();
        return Proxy();
    }
    else
    {
        /* static char nullchar = '\0'; */
        return Proxy();
    }
#endif
}

char String::operator[](size_t index) const
{
    if(index < size_)
    {
        return this->pstr_[index];
    }
    else
    {
        static char nullchar = '\0';
        return nullchar;
    }
}


//Refcount Function
void String::release_pstr()
{
    refcount_decrease();
    if(refcount() <= 0)
    {
        delete [] (pstr_ - sizeof(int)); 
    }
}

std::ostream &operator<<(std::ostream &os, const String::Proxy &pro)
{
    return os << pro.str_.pstr_[pro.index_];
}

std::ostream &operator<<(std::ostream &os, const String &str) 
{
    if(str.size_ > 0)
    {
        os << str.c_str();
    }
    return os;
}

String::Proxy &String::Proxy::operator=(char ch)
{
    if(index_ < str_.size_)
    {
        char *temp = new char[sizeof(int) + str_.capacity_ + 1]() + sizeof(int);
        strcpy(temp, str_.pstr_);
        temp[index_] = ch;
        str_.release_pstr();
        str_.pstr_ = temp;
        str_.refcount_init();
    }
    return *this;
}

std::istream &operator>>(std::istream &is, String &str)
{
    str.release_pstr();
    char ch;
    str.size_ = 0;
    str.capacity_ = 10;
    str.pstr_ = new char[sizeof(int) + str.capacity_ + 1]() + sizeof(int);
    while((ch = is.get()) && !isspace(ch) && !is.eof())
    {
        str.pstr_[str.size_] = ch;
        ++str.size_;
        if(str.size_ == str.capacity_)
        {
            str.capacity_ *= 2;
            char *temp = new char[sizeof(int) + str.capacity_ + 1]() + sizeof(int);
            strcpy(temp, str.pstr_);
            delete [] (str.pstr_ - sizeof(int));
            str.pstr_ = temp;
        }
    }
    str.refcount_init();
    return is;
}
