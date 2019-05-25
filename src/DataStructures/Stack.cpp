template <typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    int push(T);
    int pop();
    T* topPtr();
    T top();
    int size();
protected:
    struct Node;
    Node* top_;
    int size_;
};


template <typename T>
class Queue : public Stack<T>
{
public:
    Queue();
protected:
    Node* bot_;
}


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
    top_ = new Node;
    top_->next = 0;
}


template <typename T>
Stack<T>::~Stack()
{
    Node* curP = top_;
    Node* nextP = top_->next;
    while (curP)
    {
        nextP = curP->next;
        delete curP;
        curP = nextP;
    }
}


template <typename T>
int Stack<T>::push(T val)
{
    top_ = new Node(val, top_);
    return ++size_;
}


template <typename T>
int Stack<T>::pop()
{
    if (size_)
    {
        Node* newRoot = top_->next;
        delete top_;
        top_ = newRoot;
        return size_--;
    }
    return 0;
}


template <typename T>
T* Stack<T>::topPtr()
{
    return &(top_->value);
}


template <typename T>
T Stack<T>::top()
{
    return top_->value;
}


template <typename T>
int Stack<T>::size()
{
    return size_;
}