#include "Dictionary.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;

void Dictionary::ReadFile(const std::string &filename)
{
    std::ifstream ifs(filename);

    std::string word;
    
    while(ifs >> word && !ifs.eof())
    {
        //remove invalid word
        for(const auto &ch : word)
        {
        
            if(!isalpha(ch))
            {
                word.clear();
                break;
            }
        }
        //save in map
        if(!word.empty())
        {
            auto pos = dic.find(word);
            if(pos != dic.end())
            {
                ++pos->second;
            }
            else
            {
                dic.insert(std::map<std::string, int>::value_type(word, 1));
            }
        }
    }
    ifs.close();
}

void Dictionary::Store(const std::string &filename)
{
    std::ofstream ofs(filename);
    for(const auto &word : dic)
    {
        ofs << word.first << " " << word.second << endl;
    }
    ofs.close();

}

