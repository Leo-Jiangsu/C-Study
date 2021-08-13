#ifndef QUEUE_H_
#define QUEUE_H_

class Queue
{
public:
    Queue(int size = 10)
        : size_(size),
          head_(0),
          tail_(0),
          element_(new int[size + 1]())
    {}

    ~Queue() { delete [] element_; }

    void Push(int);
    void Pop();

    int get_head() const { return element_[head_]; }

    int get_tail() const { return element_[(tail_ - 1) % (size_ + 1)]; }

    bool empty() const { return head_ == tail_; }

    bool full() const { return (tail_ + 1) % (size_ + 1) == head_; }

private:
    int size_;
    int head_;//head of queue
    int tail_;//next index of tail
    int *element_;
};

#endif

