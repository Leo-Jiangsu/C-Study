#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Person
{
public:
    Person(const string &name, int age) : name_(name), age_(age) {}
    Person(const char *name, int age) : name_(string(name)), age_(age) {}
    void Display() const
    {
        cout << "name: " << name_ << endl
             << "age: " << age_ << endl;
    }
private:
    string name_;
    int age_;
};

class Employee
    : public Person
{   
    friend double AverageSalary(Employee [], int);
public:
    Employee(const string &name, int age, const string &department, double salary)
        : Person(name, age),
          department_(department),
          salary_(salary)
    {}
    ~Employee() {}
    
    void Display() const
    {
        Person::Display();
        cout << "department: " << department_ << endl;
        cout << "salary: " << salary_ << endl;
    }
private:
    string department_;
    double salary_;
};

double AverageSalary(Employee e[], int size)
{
    double total = 0;
    for(int i = 0; i < size; ++i)
    {
        total += e[i].salary_;
    }
    total /= size;
    return total;
}

int main()
{
    Employee e[3] = {
        {"leo", 20, "CS", 2000},
        {"Nancy", 21, "CC", 3000},
        {"Peter", 22, "SS", 5000}
    };
    for(int i = 0; i < 3; ++i)
    {
        e[i].Employee::Display();
    }
    cout << "average salary: " << AverageSalary(e, 3) << endl;


    return 0;
}

