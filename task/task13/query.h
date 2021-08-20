#ifndef QUERY_H_ 
#define QUERY_H_ 

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

typedef struct
{
    std::set<int> word_line_;
    int word_count_;
}WordInfo;

class TextQuery
{
public:
    TextQuery() = delete;
    TextQuery(const std::string &filename) : filename_(filename) {}
    TextQuery(const char *filename) : filename_(filename) {}

    TextQuery(const TextQuery &) = delete;
    TextQuery &operator=(const TextQuery &) = delete;
    ~TextQuery() {}

    void LoadFile();
    void Query(const std::string &) const;
    /* void Query(const char *word); */


private:
    void LoadMap();

    const std::string filename_;
    std::vector<std::string> line_;
    std::map<std::string, WordInfo> dictionary_;
    bool load_flag = false;

};

#endif

