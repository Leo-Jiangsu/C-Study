#include "query.h"
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::string;

int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        ifstream ifs(argv[1]);
        if(!ifs.fail())
        {
            TextQuery Q(argv[1]);
            Q.LoadFile();

            cout << "Type word to query: ";
            while(!cin.fail())
            {
                string word;
                cin >> word;
                Q.Query(word);
                cout << "Type word to query: ";
            }
        }
        else
        {
            cout << "File does not exist." << endl;
        }
    }
    else
    {
        cout << "No file input." << endl;
    }
    return 0;
}

