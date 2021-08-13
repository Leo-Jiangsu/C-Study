#include "String.h"
#include <string.h>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;


void TestConstructor()
{
    /* const char *str = "hello"; */
    String s1;
    String s2(s1);
    cout << s2 << endl;
}

void TestOperatorassignment()
{
    const char *str = "hello";
    String s1(str);
    /* s1 = s1.pstr_; */
    String s2;
    s1 = s2;
    /* s2 = s1; */
    cout << s1 << endl;
    cout << s2 << endl;
}

void TestOperatorPlus()
{
    String s1("hello");
    String s2("world");
    
    cout << s1 + s2 << endl;
    cout << s1 + "world"<< endl;
    cout << "hello" + s2 << endl;
}

void TestCompoundAssignmentOperator()
{
    String s1("hello");
    String s2(s1);
    s2 += "world";
    cout << s2 << endl;

    String s3(s2);
    s3 += s1;
    cout << s3 << endl;

    

}

void TestIndexOperator()
{
    String s1("hello");
    String s2(s1);
    cout << "s2[0] = " << s2[0] << endl;
    cout << "s2[2] = " << s2[2] << endl;

    s2[0] = 'H';
    cout << s2 << endl;

    cout << "s2[7] = " << s2[7] << endl;
    
}

void TestOperatorInputOutput()
{
    String s1;
    cin >> s1;
    cout << s1 << endl;
}

int main()
{
    /* TestCompoundAssignmentOperator(); */
    /* TestIndexOperator(); */
    /* TestOperatorInputOutput(); */
    /* TestOperatorPlus(); */

    return 0;
}

