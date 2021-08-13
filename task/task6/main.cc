#include "Dictionary.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    Dictionary dic;

    dic.ReadFile("The_Holy_Bible.txt");
    dic.Store("Word_Count");

    return 0;
}

