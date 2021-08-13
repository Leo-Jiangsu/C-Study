#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class StackClass
{
public:
    StackClass();
    ~StackClass();

private:
    void *operator new(size_t) = delete;
};

int main()
{
    StackClass a;
    StackClass b;
    /* StackClass *c = new StackClass(); */

    return 0;
}

