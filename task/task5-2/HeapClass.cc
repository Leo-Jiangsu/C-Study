#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class HeapClass
{
public:
    HeapClass();
    void destroy() { delete this; }

private:
    ~HeapClass();

};

int main()
{
    /* HeapClass a; */
    HeapClass *b = new HeapClass();

    b->destroy();

    return 0;
}

