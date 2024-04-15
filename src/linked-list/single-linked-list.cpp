#include <iostream>

using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node()
  {
    next = nullptr;
  }

  Node(int value = 0, Node *ptr = nullptr)
  {
    data = value;
    next = ptr;
  }
};

class SingleLinkedList
{
private:
  Node *head, *tail = nullptr;

public:
  SingleLinkedList()
  {
    head = tail = nullptr;
  }

  bool isEmpty()
  {
    return head == nullptr;
  }

  void addToHead(int value)
  {
    head = new Node(value, head);
    if (tail == nullptr)
      tail = head;
  }

  void addToTail(int value)
  {
    if (tail != nullptr)
    {
      tail->next = new Node(value);
      tail = tail->next;
    }
    else
      head = tail = new Node(value);
  }

  int deleteFromHead()
  {
    int value = head->data;
    Node *tmp = head;
    if (head == tail)
    {
      head = tail = nullptr;
    }
    else
      head = head->next;
    delete tmp;
    return value;
  }

  int deleteFromTail()
  {
    int value = tail->data;
    if (head == tail)
    {
      delete head;
      head = tail = nullptr;
    }
    else
    {
      Node *tmp = head;
      for (tmp = head; tmp->next != nullptr; tmp = tmp->next)
        ;
      delete tail;
      tail = tmp;
      tail->next = nullptr;
    }
    return value;
  }

  void deleteByValue(int val)
  {
      if (head != nullptr)
      {
        if (head == tail && head->data == val)
        {
          delete head;
          head = tail = nullptr;
        }
        else if (val == head->data)
        {
          Node *temp = head;
          head = head->next;
          delete temp;
        }
        else
        {
          Node *prev, *temp;
          for (prev = head, temp = head->next; temp != nullptr && !(temp->data != val); prev = prev->next, temp = temp->next)
          {
            if (temp != 0)
            {
              prev->next = temp->next;
              if (temp == tail)
                tail = prev;
              delete temp;
            }
          }
        }
      }
  }

  void printLinkedList()
  {
    Node *temp = head;
    while (temp != nullptr)
    {
      cout << temp->data << "->";
      temp = temp->next;
    }
  }
};

int main()
{
  SingleLinkedList *list = new SingleLinkedList();
  list->printLinkedList();
  cout << '\n';
  list->addToTail(1);
  list->addToTail(2);
  list->addToTail(3);
  list->printLinkedList();
  cout << '\n';
  list->deleteByValue(2);
  list->printLinkedList();
  cout << '\n';

  return 0;
}