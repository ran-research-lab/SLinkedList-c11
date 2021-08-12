#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H
#include <iostream>

using namespace std;

template <typename T> class SLinkedList;

// Node for the Generic Single Linked List
//  +======+========+
//  | elem | *next  |
//  +======+========+

template <typename E>
class SNode {
private:
    E elem;
    SNode<E>* next;
    friend class SLinkedList<E>;
};


// A generic single linked list

template <typename E>
class SLinkedList {
public:
    SLinkedList();
    ~SLinkedList();
    bool empty() const;
    const E& front() const;
    void addFront(const E& e);
    void removeFront();
    void display(ostream &out) const;
    string toString() const;
private:
    SNode<E>* head;
};

template <typename E>
ostream& operator<<(ostream &out, const SLinkedList<E> &L);


#endif // SLINKEDLIST_H
