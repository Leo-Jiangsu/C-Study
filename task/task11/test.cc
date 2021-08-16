#include "String.h"

using std::cout;
using std::endl;
using std::cin;

/* static int test_total_count = 0; */
/* static int test_pass_count = 0; */


void TestConstructor()
{
    String s1;
    cout << s1 << endl;
    String s2("Hello");
    cout << "s2 = " << s2 << endl;
    cout << "s2.ref = " << s2.refcount() << endl;
    String s3(s2);
    cout << "s3 = " << s3 << endl;
    cout << "s2.ref = " << s2.refcount() << endl;
    cout << "s3.ref = " << s3.refcount() << endl;

}

void TestCopyOperator()
{
    String s1;
    cout << s1 << endl;
    String s2;
    s2 = "Hello";
    cout << "s2 = " << s2 << endl;
    cout << "s2.ref = " << s2.refcount() << endl;
    String s3 = "world";
    s3 = s2;
    cout << "s3 = " << s3 << endl;
    cout << "s2.ref = " << s2.refcount() << endl;
    cout << "s3.ref = " << s3.refcount() << endl;
}

void TestPlusOperator()
{
#if 0
    String s1;
    cout << s1 << endl;
    String s2;
    s2 = "Hello";
    cout << "s2 = " << s2 << endl;
    cout << "s2.ref = " << s2.refcount() << endl;
    String s3 = "world";
    cout << "s3 = " << s3 << endl;
    cout << "s2.ref = " << s2.refcount() << endl;
    cout << "s3.ref = " << s3.refcount() << endl;

    s2 += s3;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s2.ref = " << s2.refcount() << endl;
    cout << "s3.ref = " << s3.refcount() << endl;
#else
    String s1;
    cout << s1 << endl;
    String s2;
    s2 = "Hello";
    cout << "s2 = " << s2 << endl;
    cout << "s2.ref = " << s2.refcount() << endl;
    String s3 = s2;
    cout << "s3 = " << s3 << endl;
    cout << "s2.ref = " << s2.refcount() << endl;
    cout << "s3.ref = " << s3.refcount() << endl;
    s2 += "world";
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s2.ref = " << s2.refcount() << endl;
    cout << "s3.ref = " << s3.refcount() << endl;

#endif
}

void TestIndex()
{
    String s1 = "Hello";
    String s2 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s1.ref = " << s2.refcount() << endl;
    cout << "s2.ref = " << s2.refcount() << endl;
    cout << endl;

    s1[0];
    cout << "s1[0] = " << s1[0] << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s1.ref = " << s2.refcount() << endl;
    cout << "s2.ref = " << s2.refcount() << endl;
    cout << endl;

    s1[0] = 'h';
    cout << s1[0] << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s1.ref = " << s2.refcount() << endl;
    cout << "s2.ref = " << s2.refcount() << endl;


}

void TestOperatorInput()
{
    String s1 = "Hello";
    String s2 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s1.ref = " << s2.refcount() << endl;
    cout << "s2.ref = " << s2.refcount() << endl;
    cout << endl;

    cin >> s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s1.ref = " << s2.refcount() << endl;
    cout << "s2.ref = " << s2.refcount() << endl;
    cout << endl;

    s2 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s1.ref = " << s2.refcount() << endl;
    cout << "s2.ref = " << s2.refcount() << endl;
    cout << endl;

    

}

int main()
{
    TestOperatorInput();
    return 0;
}

