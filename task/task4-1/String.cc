#include "String.h"
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void String::print() const
{
    if(pstr_)
    {
        cout << pstr_ << endl;
    }
}


String::String(const char *pstr)
    :pstr_(new char[strlen(pstr) + 1]())
{
    strcpy(pstr_, pstr);
}

String::String(const String &rhs)
    : String::String(rhs.pstr_)
{}

String &String::operator=(const String &rhs)
{
    if(&rhs != this)
    {
        delete [] pstr_;
        pstr_ = new char[strlen(rhs.pstr_) + 1]();
        strcpy(pstr_, rhs.pstr_);
    }
    return *this;
}

