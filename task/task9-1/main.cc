#include "Base.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    int i=2;int j=7;
    Base x(i);Base y(j);
    cout<<(x+y==j-i)<<endl;
    return 0;
}

