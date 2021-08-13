#include "String.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void test()
{
    String str1;
    str1.print();

    String str2 = "Hello,world";
    String str3("wangdao");

    str2.print();       
    str3.print();   

    String str4 = str3;
    str4.print();

    str4 = str2;
    str4.print();
}


int main()
{
    test();
    return 0;
}

