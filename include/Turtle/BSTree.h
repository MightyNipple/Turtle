#pragma once


#include <Turtle/Queue.h>

/*
   WAVL tree
*/



template <typename TKey, typename TValue>
class BSTree
{
public:
    BSTree();
    ~BSTree();
    int size();
    TValue& operator[](const TKey&);
    TValue& get(const TKey&, const TValue&) const;
    TValue* getPtr(const TKey&) const;
protected:
    struct Node;
    Node* insert(const TKey&);
    int remove(const TKey&);
    void rotateLeft(Node**);
    void rotateRight(Node**);
    Node* root_;
    int size_;
};



template <typename TKey, typename TValue>
struct BSTree<TKey, TValue>::Node
{
    TKey key;
    TValue value;
    Node* right;
    Node* left;
    char rank;
    Node(const TKey& key_)
    {
        key = key_;
        right = 0;
        left = 0;
        rank = 0;
    }
};


template <typename TKey, typename TValue>
BSTree<TKey, TValue>::BSTree()
{
    root_ = 0;
    size_ = 0;
}


template <typename TKey, typename TValue>
BSTree<TKey, TValue>::~BSTree()
{
    Queue<Node*> deletionQueue;
    if (root_)
    {
        deletionQueue.push(root_);
    }
    while (deletionQueue.size())
    {
        Node* node = deletionQueue.top();
        if (node->left)
        {
            deletionQueue.push(node->left);
        }
        if (node->right)
        {
            deletionQueue.push(node->right);
        }
        delete node;
        deletionQueue.pop();
    }
}


template <typename TKey, typename TValue>
void BSTree<TKey, TValue>::rotateLeft(Node** x)
{
    Node*& parent = *x;
    Node* tmp = parent->right;
    parent->right = tmp->left;
    tmp->left = parent;
    parent = tmp;
}


template <typename TKey, typename TValue>
void BSTree<TKey, TValue>::rotateRight(Node** x)
{
    Node*& parent = *x;
    Node* tmp = parent->left;
    parent->left = tmp->right;
    tmp->right = parent;
    parent = tmp;
}


template <typename TKey, typename TValue>
typename BSTree<TKey, TValue>::Node* BSTree<TKey, TValue>::insert(const TKey& key_)
{
    if (!root_)
    {
        root_ = new Node(key_);
        ++size_;
        return root_;
    }
    Node* curNode = root_;
    Node** path[root_->rank + 2];
    int i = 0;
    path[0] = &root_;
    while (curNode)
    {
        
        if (key_ < curNode->key)
        {
            path[++i] = &(curNode->left);
            curNode = curNode->left;
        }
        else if (key_ > curNode->key)
        {
            path[++i] = &(curNode->right);
            curNode = curNode->right;
        }
        else
        {
            return curNode;
        }
    }
    *path[i] = new Node(key_);
    curNode = *path[i];
    ++size_;
    while (true)
    {
        if (i == 0 || (*path[i - 1])->rank - (*path[i])->rank != 0)
        {
            return curNode;
        }
        if (*path[i] == (*path[i - 1])->right)
        {
            char sibRankDif = (*path[i - 1])->left == 0 ? (*path[i - 1])->rank + 1 :
                              (*path[i - 1])->rank - (*path[i - 1])->left->rank;
            if (sibRankDif == 1)
            {
                (*path[i - 1])->rank += 1;
                --i;
                continue;
            }
            else
            {
                if (!((*path[i])->left) || (*path[i])->rank - (*path[i])->left->rank == 2)
                {
                    (*path[i - 1])->rank -= 1;
                    rotateLeft(path[i - 1]);
                }
                else
                {
                    (*path[i])->left->rank += 1;
                    (*path[i])->rank -= 1;
                    (*path[i - 1])->rank -= 1;
                    rotateRight(path[i]);
                    rotateLeft(path[i - 1]);
                }
                return curNode;
            }
        }
        else
        {
            char sibRankDif = (*path[i - 1])->right == 0 ? (*path[i - 1])->rank + 1 :
                              (*path[i - 1])->rank - (*path[i - 1])->right->rank;
            if (sibRankDif == 1)
            {
                (*path[i - 1])->rank += 1;
                --i;
                continue;
            }
            else
            {
                if (!((*path[i])->right) || (*path[i])->rank - (*path[i])->right->rank == 2)
                {
                    (*path[i - 1])->rank -= 1;
                    rotateRight(path[i - 1]);
                }
                else
                {
                    (*path[i])->right->rank += 1;
                    (*path[i])->rank -= 1;
                    (*path[i - 1])->rank -= 1;
                    rotateLeft(path[i]);
                    rotateRight(path[i - 1]);
                }
                return curNode;
            }
        }
    }
}


/*
 To be implemented
*/
template <typename TKey, typename TValue>
int BSTree<TKey, TValue>::remove(const TKey& val)
{
    if (!root_)
    {
        return 0;
    }
    Node* curNode = root_;
    Node** path[root_->rank + 2];
    int i = 0;
    path[0] = &root_;
    while (curNode)
    {
        
        if (val < curNode->value)
        {
            path[++i] = &(curNode->left);
            curNode = curNode->left;
        }
        else if (val > curNode->value)
        {
            path[++i] = &(curNode->right);
            curNode = curNode->right;
        }
        else
        {
            break;
        }
    }
    if (!curNode)
    {
        return size_;
    }
    int iToRemove = i;
    if (curNode->left)
    {
        *path[++i] = curNode->left;
        curNode = curNode->left;
    }
    while (curNode->right)
    {
        path[++i] = &(curNode->right);
        curNode = curNode->right;
    }
    if (curNode->left)
    {
        
    }
    return 0;
}


template <typename TKey, typename TValue>
int BSTree<TKey, TValue>::size()
{
    return size_;
}


template <typename TKey, typename TValue>
TValue& BSTree<TKey, TValue>::operator[](const TKey& key_)
{
    return insert(key_)->value;
}


template <typename TKey, typename TValue>
TValue& BSTree<TKey, TValue>::get(const TKey& key_, const TValue& returnOnFail_) const 
{
    Node* curNode = root_;
    while (curNode)
    {
        
        if (key_ < curNode->key)
        {
            curNode = curNode->left;
        }
        else if (key_ > curNode->key)
        {
            curNode = curNode->right;
        }
        else
        {
            return curNode->value;
        }
    }
    return returnOnFail_;
}


template <typename TKey, typename TValue>
TValue* BSTree<TKey, TValue>::getPtr(const TKey& key_) const
{
    Node* curNode = root_;
    while (curNode)
    {
        
        if (key_ < curNode->key)
        {
            curNode = curNode->left;
        }
        else if (key_ > curNode->key)
        {
            curNode = curNode->right;
        }
        else
        {
            return &(curNode->value);
        }
    }
    return 0;
}
