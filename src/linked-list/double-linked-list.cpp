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

template <class T>
class DoubleLinkedList
{
protected:
    Node *head, *tail;

public:
    DoubleLinkedList()
    {
        head = tail = nullptr;
    }

    void addToTail(const T &);
    T deleteFromTail();
};

template <class T>
void DoubleLinkedList<T>::addToTail(const T &val)
{
    if (tail != nullptr)
    {
        tail = new Node<T>(val, nullptr, tail);
        tail->prev->next = tail;
    }
    else
        head = tail = new Node<T>(val);
}

template <class T>
T DoubleLinkedList<T>::deleteFromTail()
{
    T val = tail->data;
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    return val;
}
