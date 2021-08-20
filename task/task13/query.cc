#include "query.h"
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::istringstream;
using std::string;
using std::set;
using std::map;
using std::pair;


void TextQuery::LoadFile()
{
    if(!load_flag)
    {
        ifstream ifs(filename_);
        while(!ifs.eof())
        {
            string line;
            getline(ifs, line);
            line_.push_back(line);
        }
        LoadMap();
        load_flag = true;
    }
}

void TextQuery::LoadMap()
{
    for(int i = 0; line_.begin() + i != line_.end(); ++i)
    {
        //line i; i = [0, 1, ...]
        string word;
        istringstream iss(line_[i]);
        while(iss >> word)
        {
            bool isword = true;
            for(auto &ch : word)
            {
                if(!isalpha(ch))
                {
                    isword = false;
                    break;
                }
            }
            if(isword)
            {
                //save in map
                auto loc = dictionary_.find(word);
                if(loc == dictionary_.end())
                {
                    //Insert
                    WordInfo info;
                    info.word_line_.insert(i);//line begins of 0
                    info.word_count_ = 1;
                    pair<string, WordInfo> temp_mappair(word, info);
                    dictionary_.insert(temp_mappair);
                }
                else
                {
                    //Count
                    ++loc->second.word_count_;
                    loc->second.word_line_.insert(i);
                }
            }
        }
    }
}

void TextQuery::Query(const std::string &queryword) const
{
    auto loc = dictionary_.find(queryword);
    if(loc != dictionary_.end())
    {
        cout << "Word occurs " << loc->second.word_count_ << " times." << endl;
        int i = 0;
        for(auto it = loc->second.word_line_.begin(); 
            it != loc->second.word_line_.end() && i < 5; 
            ++it, ++i)
        {
            cout << "\t(line " << *it + 1 << ")" // line begins of 1
                 << line_[*it] << endl;
        }
    }
    else
    {
        cout << "Word " << queryword <<  " does not occur." << endl;

    }
}
