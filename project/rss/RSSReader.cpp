#include "tinyxml2.h"
#include "RSSReader.h"
#include <iostream>
#include <fstream>
#include <regex>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::regex;
using namespace tinyxml2;


void RSSReader::RSSParse(const char *rssfile)
{
    XMLDocument doc;
    doc.LoadFile(rssfile);

    XMLElement *root = doc.RootElement();
    XMLElement *channel = root->FirstChildElement();
    XMLElement *item = channel->FirstChildElement("item");

    do
    {
        RSSItem newitem; 
        XMLElement *temp;
        if((temp = item->FirstChildElement("link")))
        {
            newitem.link = temp->GetText();
        }
        if((temp = item->FirstChildElement("description")))
        {
            /* cout << temp->GetText() << endl; */
            regex self_regex("<.*?>");
            newitem.description= regex_replace(temp->GetText(), self_regex, "");
        }
        if((temp = item->FirstChildElement("content:encoded")))
        {
            /* cout << temp->GetText() << endl; */
            regex self_regex("<.*?>");
            newitem.content = regex_replace(temp->GetText(), self_regex, "");
        }
        if((temp = item->FirstChildElement("title")))
        {
            newitem.title = temp->GetText();
            rss_item_.push_back(newitem);
        }
    }while((item = item->NextSiblingElement("item")));

}

void RSSReader::ContentRegex()
{
    for(auto &item : rss_item_)
    {
        regex self_regex("<.*?>");
        item.content = regex_replace(item.content, self_regex, "");
    }
}


void RSSReader::showvec() const
{
    for(auto &i : rss_item_)
    {
        cout << i.title << endl;
        cout << i.link << endl;
        cout << i.description << endl;
        cout << i.content << endl;
    }

}

void RSSReader::Dump(const std::string &filename)
{
    std::ofstream ofs(filename);
    int index = 1;
    for(auto &i : rss_item_)
    {
        ofs << "<doc>" << endl;
        ofs << "\t<docid>" << index  << "</docid>" << endl;
        ++index;
        ofs << "\t<title>" << i.title << "</title>" << endl;

        ofs << "\t<link>" << i.link<< "</link>" << endl;

        ofs << "\t<description>" << i.description<< "</description>" << endl;

        ofs << "\t<content>" << i.content<< "</content>" << endl;

        ofs << "</doc>" << endl;
    }
    ofs.close();
}

