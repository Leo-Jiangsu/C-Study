#ifndef LIST_H_
#define LIST_H_

typedef struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
}Node;

class List
{
public:
    List() 
        : head_(nullptr),
          tail_(nullptr), 
          size_(0)
    {}

    ~List() { while(size_ > 0){ pop_back(); } }

    void push_front(int data);//在头部进行插入
    void push_back(int data);//在尾部进行插入
    void pop_front();//在链表头部进行删除
    void pop_back();//在链表的尾部进行删除
    bool find(int data) const;//在链表中进行查找
    void insert(int pos, int data);//在指定位置后面插入pos
    void display() const; //打印链表
    void erase(int data);//删除一个指定的节点   

private:
    Node *head_;
    Node *tail_;
    int size_;
};

#endif

