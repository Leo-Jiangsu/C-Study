#ifndef RSSREADER_H_
#define RSSREADER_H_

#include <string>
#include <vector>

typedef struct 
{
    std::string title;
    std::string link;
    std::string description;
    std::string content;

}RSSItem;

class RSSReader
{
public:
    RSSReader() {}
    ~RSSReader() {}

    void RSSParse(const char *);
    void ContentRegex();
    void Dump(const std::string &);
    void showvec() const;

private:
    std::vector<RSSItem> rss_item_;
};

#endif

