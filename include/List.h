#ifndef LIST_H
#define LIST_H
#include <Node.h>
#include <ostream>
#include <iostream>

using std::cout;
using std::endl;

using std::ostream;

template <typename T>
class List
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    List()
    {
    }
    Node<T> *getHead()
    {
        return this->head;
    }
    void add(T value)
    {
        Node<T> *temp = new Node<T>(value);

        if (head == nullptr)
        {
            head = temp;
            head->setNext(temp);
            tail = temp;
        }
        else
        {
            tail->setNext(temp);
            tail = tail->getNext();
        }
    }
    friend ostream &operator<<(ostream &os, List list)
    {
        os << *list.getHead() << endl;

        return os;
    }
};

#endif