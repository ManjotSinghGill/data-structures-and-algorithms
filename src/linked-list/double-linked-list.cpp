#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next, *prev;

    Node()
    {
        next = prev = nullptr;
    }

    Node(const T &val, Node *n = nullptr, Node *p = nullptr)
    {
        data = val;
        next = n;
        prev = p;
    }
};

template<class T>
class DoubleLinkedList{
    protected:
    Node *head, *tail;
    public:
    DoubleLinkedList(){
        head = tail = nullptr;
    }

    
};