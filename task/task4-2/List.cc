#include "List.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void List::push_front(int data)//在头部进行插入
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->pre = nullptr;

    if(size_ == 0)
    {
        new_node->next = nullptr;
        head_ = tail_ = new_node;
    }
    else
    {
        new_node->next = head_;
        head_->pre = new_node;
        head_ = new_node;
    }
    ++size_;
}

void List::push_back(int data)//在尾部进行插入
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    if(size_ == 0)
    {
        new_node->pre = nullptr;
        head_ = tail_ = new_node;
    }
    else
    {
        new_node->pre = tail_;
        tail_->next = new_node;
        tail_ = new_node;
    }
    ++size_;
}


void List::pop_front()//在链表头部进行删除
{
    if(size_ == 1)
    {
        delete tail_;
        --size_;
        head_ = tail_ = nullptr;
    }
    else if(size_ > 0)
    {
        Node *temp = head_;
        head_ = head_->next;
        head_->pre = nullptr;
        delete temp;
        --size_;
    }
}
void List::pop_back()//在链表的尾部进行删除
{
    if(size_ == 1)
    {
        delete tail_;
        --size_;
        head_ = tail_ = nullptr;
    }
    else if(size_ > 0)
    {
        Node *temp = tail_;
        tail_ = tail_->pre;
        tail_->next = nullptr;
        delete temp;
        --size_;
    }
}

bool List::find(int data) const//在链表中进行查找
{
    Node *temp = head_;
    while(temp && data != temp->data)
    {
        temp = temp->next;
    }
    return temp != nullptr;

}

void List::insert(int pos, int data)//在指定位置后面插入pos
{
    if(pos == 0)
    {
        push_front(data);
    }
    else if(pos == size_)
    {
        push_back(data);
    }
    else if(pos > 0 && pos < size_)
    {
        Node *temp = head_;
        while(pos > 0)
        {
            temp = temp->next;
            --pos;
        }
        //push before temp
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = temp;
        new_node->pre = temp->pre;
        temp->pre->next = new_node;
        temp->pre = new_node;
        ++size_;
    }

}

void List::display() const //打印链表
{
    if(size_ > 0)
    {

        Node *temp = head_;
        while(temp && temp != tail_)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
    else
    {
        cout << "Empty List" << endl;
    }
}

void List::erase(int data)//删除一个指定的节点   
{
    Node *temp = head_;
    while(temp && data != temp->data)
    {
        temp = temp->next;
    }
    if(temp == head_)
    {
        pop_front();
    }
    else if(temp == tail_)
    {
        pop_back();
    }
    else if(temp)
    {
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        delete temp;
        --size_;
    }
}

