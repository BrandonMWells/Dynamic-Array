#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>

using std::ostream;

template <class T>
struct Node {
	T info;
	Node<T>* next;
};

template <class T>
class LinkedList {
public:
    LinkedList() { head = nullptr; }
    void addEl(const T & el);           // O(1) steps
    bool findEl(const T & el);          // O(n) steps
    bool retrieveEl(T & el);            // O(n) steps
    bool removeEl(T & el);              // O(n) steps
    template <class T1>
    friend ostream & operator << (ostream & os, LinkedList<T1> myList);
private:
	Node<T> * head;
};

template <class T>
void LinkedList<T>::addEl(const T & el) {   // O(1) step
    Node<T> * temp = new Node<T>;
    temp->info = el;
    temp->next = head;
    head = temp;
}

template <class T>
bool LinkedList<T>::findEl(const T & el) {
    Node<T> * curr = head;                      // 1
    while (curr != nullptr) {                   // loop max of n steps
        if (el == curr->info) return true;      // check max of n steps
        curr = curr->next; // curr should now point to the next node..
    }
    return false;
}

template <class T>
bool LinkedList<T>::retrieveEl(T & el) {
    Node<T> * curr = head;
    while (curr != nullptr) {
        if (el == curr->info) {
            el = curr->info;
            return true;
        }
        curr = curr->next; // curr should now point to the next node..
    }
    return false;
}

template <class T>
bool LinkedList<T>::removeEl(T & el) {
    if (head == nullptr) return false;
    Node<T> * curr = head;
    if (el == head->info) {
        el = head->info;
        head = curr->next;
        delete curr;
        return true;
    }
    while (curr->next != nullptr) {
        if (el == curr->next->info) {
            el = curr->next->info;
            Node<T> * temp = curr->next;
            curr->next = temp->next;
            delete temp;
            return true;
        }
        curr = curr->next; // curr should now point to the next node..
    }
    return false;
}

template <class T>
ostream & operator << (ostream & os, LinkedList<T> myList) {
    Node<T> * curr = myList.head;
    while (curr != nullptr) {
        os << curr->info << "->";
        curr = curr->next; // curr should now point to the next node..
    }
    return os;
}


#endif // LINKEDLIST_H_INCLUDED
