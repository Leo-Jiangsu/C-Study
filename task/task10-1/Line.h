#ifndef LINE_H_
#define LINE_H_

class Line
{
public:
    Line(int, int, int, int);
    ~Line();
    void PrintLine() const;
private:
    class LinePimpl;
    LinePimpl *pline_;
};

#endif

