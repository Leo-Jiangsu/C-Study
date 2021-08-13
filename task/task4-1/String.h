#ifndef STRING_H_ 
#define STRING_H_ 


class String
{
public:
    String()
        :pstr_(nullptr)
    {}

    String(const char *pstr);
    String(const String &rhs);
    String &operator=(const String &rhs);
    ~String() { delete [] pstr_; }

    void print() const;

private:
    char *pstr_;
};

#endif

