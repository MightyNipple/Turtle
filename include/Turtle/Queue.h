#pragma once

#include "Stack.h"


template <typename T>
class Queue : public Stack<T>
{
public:
    Queue();
    int push(const T&);
protected:
    using typename Stack<T>::Node;
    using Stack<T>::size_;
    using Stack<T>::top_;
    Node* bot_;
};


template <typename T>
Queue<T>::Queue()
{
    bot_ = 0;
}


template <typename T>
int Queue<T>::push(const T& val)
{
    if (bot_)
    {
        Node* oldBot = bot_;
        bot_ = new Node(val, 0);
        oldBot->next = bot_;
    }
    else
    {
        bot_ = new Node(val, 0);
        top_ = bot_;
    }
    return ++size_;
}

