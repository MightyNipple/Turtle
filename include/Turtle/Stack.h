#pragma once


template <typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    int push(const T&);
    int pop();
    T* topPtr();
    T& top();
    int size();
protected:
    struct Node;
    Node* top_;
    int size_;
};


template <typename T>
struct Stack<T>::Node
{
    T value;
    Node* next;
    Node(){}
    Node(T val, Node* nxt)
    {
        value = val;
        next = nxt;
    }
};


template <typename T>
Stack<T>::Stack()
{
    size_ = 0;
    top_ = 0;
}


template <typename T>
Stack<T>::~Stack()
{
    Node* curP = top_;
    Node* nextP;
    while (curP)
    {
        nextP = curP->next;
        delete curP;
        curP = nextP;
    }
}


template <typename T>
int Stack<T>::push(const T& val)
{
    top_ = new Node(val, top_);
    return ++size_;
}


template <typename T>
int Stack<T>::pop()
{
    if (top_)
    {
        Node* newTop = top_->next;
        delete top_;
        top_ = newTop;
        return --size_;
    }
    return 0;
}


template <typename T>
T* Stack<T>::topPtr()
{
    return &(top_->value);
}


template <typename T>
T& Stack<T>::top()
{
    return top_->value;
}


template <typename T>
int Stack<T>::size()
{
    return size_;
}
