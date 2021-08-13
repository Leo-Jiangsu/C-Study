#include "String.h"
#include <string.h>

using std::cout;
using std::endl;
using std::cin;


String::String(const char *pstr)
    : pstr_(new char[strlen(pstr) + 1]())
{
    strcpy(pstr_, pstr);
}

String::String(const String &str)
    : pstr_(new char[str.size() + 1]())
{
    strcpy(pstr_, str.pstr_);
}

String &String::operator=(const char *pstr)
{
    if(pstr != this->pstr_)
    {
        delete [] pstr_;
        pstr_ = new char[strlen(pstr) + 1]();
        strcpy(pstr_, pstr);
    }
    return *this;
}

String &String::operator=(const String &str)
{
    if(&str != this)
    {
        delete [] pstr_;
        pstr_ = new char[str.size() + 1]();
        strcpy(pstr_, str.pstr_);
    }
    return *this;
}

String &String::operator+=(const char *pstr)
{
    if(pstr)
    {
        char *temp = pstr_;
        pstr_ = new char[strlen(temp) + strlen(pstr) + 1]();
        strcpy(pstr_, temp);
        strcat(pstr_, pstr);
        delete [] temp;
    }
    return *this;
}

String &String::operator+=(const String &str)
{
    if(str.pstr_)
    {
        char *temp = pstr_;
        pstr_ = new char[strlen(temp) + str.size() + 1]();
        strcpy(pstr_, temp);
        strcat(pstr_, str.pstr_);
        delete [] temp;
    }
    return *this;
}

char &String::operator[](size_t index)
{
    if(index < size())
    {
        return pstr_[index];
    }
    else
    {
        static char nullchar = '\0';
        return nullchar;
    }
}

const char &String::operator[](size_t index) const
{
    if(index < size())
    {
        return pstr_[index];
    }
    else
    {
        static char nullchar = '\0';
        return nullchar;
    }
}


const char *String::c_str() const
{
    return pstr_;
}


inline
size_t String::size() const
{
    return strlen(pstr_);
    /* return pstr_? strlen(pstr_) : 0; */
}

bool operator==(const String &lhs, const String &rhs)
{
    return strcmp(lhs.pstr_, rhs.pstr_) == 0;
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !operator==(lhs, rhs);
}

bool operator>(const String &lhs, const String &rhs)
{
    return strcmp(lhs.pstr_, rhs.pstr_) > 0;
}

bool operator<(const String &lhs, const String &rhs)
{
    return strcmp(lhs.pstr_, rhs.pstr_) < 0;
}
bool operator>=(const String &lhs, const String &rhs)
{
    return strcmp(lhs.pstr_, rhs.pstr_) >= 0;
}
bool operator<=(const String &lhs, const String &rhs)
{
    return strcmp(lhs.pstr_, rhs.pstr_) <= 0;
}

std::ostream &operator<<(std::ostream &os, const String &str)
{
    if(str.pstr_)
    {
        os << str.pstr_;
    }
    return os;
}

std::istream &operator>>(std::istream &is, String &str)
{
    char ch;
    char *temp = new char[10]();
    int i = 0;
    while((ch = is.get()) && !isspace(ch) && !is.eof())
    {
        temp[i++] = ch;
        if(i == 10)
        {
            str += temp;
            delete [] temp;
            temp = new char[10]();
            i = 0;
        }
    }
    str += temp;
    delete [] temp;
    return is;
}


String operator+(const String &lhs, const String &rhs)
{
    String temp(lhs);
    temp += rhs;
    return temp;
}
String operator+(const String &lhs, const char *rhs)
{
    return operator+(lhs, String(rhs));

}

String operator+(const char *lhs, const String &rhs)
{
    return operator+(String(lhs), rhs);
}

