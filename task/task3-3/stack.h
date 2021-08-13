#ifndef STACK_H_
#define STACK_H_

class Stack
{
public:
    Stack(unsigned int size = 10)
        : size_(size),
          top_index_(-1),
          element_(new int[size]())
    {}

    ~Stack()
    {
        delete [] element_;
    }

    void Push(int data);

    void Pop();

    int top() const
    {
        return element_[top_index_];
    }

    bool empty() const
    {
        return top_index_ == -1;
    }

    bool full() const
    {
        return top_index_ == size_;
    }

private:
    int size_;
    int top_index_;
    int *element_;
};

#endif

