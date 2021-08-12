#include "slinkedlist.h"
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

template <typename E>
SLinkedList<E>::SLinkedList() : head(NULL) { }

template <typename E>
bool SLinkedList<E>::empty() const
{ return head == NULL; }

template <typename E>
const E& SLinkedList<E>::front() const
{ return head->elem; }

template <typename E>
SLinkedList<E>::~SLinkedList() {
    while (!empty())
        removeFront();
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {
    SNode<E>* v = new SNode<E>;
    v->elem = e;
    v->next = head;
    head = v;
}

template <typename E>
void SLinkedList<E>::removeFront() {
    SNode<E>* old = head;
    head = old->next;
    delete old;
}

template <typename E>
void SLinkedList<E>::display(ostream &out) const{
    SNode<E> *curr = head;
    while (curr != NULL) {
        out << curr->elem << " ";
        curr = curr->next;
    }
}

template <typename E>
string SLinkedList<E>::toString() const{
    stringstream ss;
    SNode<E> *curr = head;
    while (curr != NULL) {
        ss << curr->elem <<  " ";
        curr = curr->next;
    }
    return ss.str();
}

template <typename E>
ostream& operator<<(ostream &out, const SLinkedList<E> &L) {
    L.display(out);
    return out;
}
