#include <iostream>
#include <math.h>


class Circle
{
public:
    Circle(double radius = 0) : radius_(radius) {}
    ~Circle() {}

    double GetArea() const { return M_PI * radius_ * radius_; }
    double GetPerimeter() const { return 2 * M_PI *radius_; }
    void Show() const
    {
        std::cout << "radius    = " << radius_ << std::endl
                  << "area      = " << GetArea() << std::endl
                  << "Perimeter = " << GetPerimeter() << std::endl;
    }
private:
    double radius_;
};

class Cylinder
    : public Circle
{
public:
    Cylinder(double radius, double height) : Circle(radius), height_(height) {}
    ~Cylinder() {}

    double GetVolume() const { return GetArea() * height_; }
    void ShowVolume() const { std::cout << "Volume = " << GetVolume() << std::endl; }

private:
    double height_;
};

int main()
{
    Cylinder c(2, 3);
    c.Show();
    c.ShowVolume();
    return 0;
}
