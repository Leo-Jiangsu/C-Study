#include "RSSReader.h"
#include "tinyxml2.h"
#include <iostream>
#include <regex>

using namespace tinyxml2;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::regex;

void test(const char *filename)
{
    XMLDocument doc;
    doc.LoadFile(filename);
    XMLElement *root = doc.RootElement();

    XMLElement *channel = root->FirstChildElement();
    cout << channel->Name() << endl;

    XMLElement *item = channel->FirstChildElement("item");
    do
    {
        XMLElement *ele = item->FirstChildElement();
        while(ele)
        {
            cout << ele->Name() << endl;
            ele = ele->NextSiblingElement();
        }
        while(1);
    }while((item = item->NextSiblingElement("item")));

    while(1);

    /* XMLElement *first_element = doc.RootElement().FirstChild(); */
    const char* title = doc.FirstChildElement("title")->FirstChildElement()->GetText();
    printf( "Name of play (1): %s\n", title  );


#if 0
    const char* title = doc.FirstChildElement( "PLAY"  )
        ->FirstChildElement( "TITLE"  )->GetText();
    printf( "Name of play (1): %s\n", title  );
    XMLText* textNode = doc.FirstChildElement( "PLAY"  )
        ->FirstChildElement( "TITLE"  )->FirstChild()->ToText();
    title = textNode->Value();
    printf( "Name of play (2): %s\n", title  );
#endif
}

void TestRSSReader(const char *filename)
{
    RSSReader rs;
    rs.RSSParse(filename);
    /* rs.ContentRegex(); */
    rs.Dump("pagelib.txt");
    /* rs.showvec(); */
}

void TestRegex()
{
    string content("<p align=\"center\"><a href= target=_blank><img src=""></a></p>\n4081\n4082  --></p>");
    regex self_regex("<.*?>");
    cout << regex_replace(content, self_regex, "") << endl;
}
int main(int argc, char *argv[])
{
    /* TestRegex(); */

    if(argc > 1)
    {
        TestRSSReader(argv[1]);
        /* test(argv[1]); */
    }
    else
    {
        TestRSSReader("coolshell.xml");
    }

    return 0;
}

