#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <map>
#include <string>

class Dictionary
{
public:
    Dictionary() {}
    ~Dictionary() {}

    void ReadFile(const std::string &filename);
    void Store(const std::string &filename);


private:
    std::map<std::string, int> dic;

};

#endif

