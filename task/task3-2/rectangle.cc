#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Rectangle
{
public:
    Rectangle(int length = 1, int width = 1)
        : length_(length),
          width_(width)
    {}
    ~Rectangle()
    {}
    void print() const
    {
        cout << "length: " << length_
             << ", width: " << width_
             << endl
             << "perimeter: " << perimeter()
             << ", area = " << area()
             << endl;
    }
    int perimeter() const
    {
        return (length_ + width_) * 2;
    }
    int area() const
    {
        return length_ * width_;
    }

private:
    int length_;
    int width_;
};

int main()
{
    Rectangle r(3, 5);
    r.print();
    
    return 0;
}

