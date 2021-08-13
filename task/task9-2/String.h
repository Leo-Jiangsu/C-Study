#ifndef STRING_H_
#define STRING_H_

#include <iostream>

class String
{
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend std::istream &operator>>(std::istream &, String &);
    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);

    friend bool operator>(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend bool operator>=(const String &, const String &);
    friend bool operator<=(const String &, const String &);

public:
    String()
        : pstr_(new char[1]())
    {}
    String(const char *);
    String(const String &);
    ~String() { if(pstr_){ delete [] pstr_; } }

    String &operator=(const char *);
    String &operator=(const String &);
    String &operator+=(const char *);
    String &operator+=(const String &);
    char &operator[](size_t index);
    const char &operator[](size_t index) const;

    const char *c_str() const;

    size_t size() const;

private:
    char *pstr_;
};

String operator+(const String &, const String &);
String operator+(const String &, const char *);
String operator+(const char *, const String &);

#endif

