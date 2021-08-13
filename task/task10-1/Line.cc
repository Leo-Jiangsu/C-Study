#include "Line.h"
#include <iostream>

using std::cout;
using std::endl;

class Line::LinePimpl
{
public:
    LinePimpl(int x1, int y1, int x2, int y2)
        : p1_(x1, y1),
          p2_(x2, y2)
    {}
    ~LinePimpl() {}

    void PrintLine() const;

private:
    typedef struct Point
    {
        Point(int x, int y)
            : x_(x),
              y_(y)
        {}
        int x_;
        int y_;
    }Point;
    Point p1_, p2_;

};

inline
void Line::LinePimpl::PrintLine() const
{
    cout << "(" << p1_.x_ << ", " << p1_.y_ << ") --> "
         << "(" << p2_.x_ << ", " << p2_.y_ << ")" << endl;
}

Line::Line(int x1, int y1, int x2, int y2)
    : pline_(new LinePimpl(x1, y1, x2, y2))
{}

Line::~Line(){ delete pline_; }

/* inline */
void Line::PrintLine() const
{
    pline_->PrintLine();
}
