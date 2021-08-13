#include <string.h>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Student
{
public:
    Student(int id, const char *name, unsigned int age)
        : id_(id),
          name_(new char[strlen(name) + 1]()),
          age_(age)
    {
        strcpy(name_, name);
    }

    ~Student()
    {
        delete [] name_;
    }

    void print() const
    {
        cout << "id: " << id_
             << ", name: " << name_
             << ", age: " << age_
             << endl;
    }

private:
    int id_;
    char *name_;
    unsigned int age_;
};

int main()
{
    Student a(1, "Lee", 15);
    a.print();
    Student b(7, "Peter", 16);
    b.print();
    Student c(4, "Nancy", 14);
    c.print();
    return 0;
}


