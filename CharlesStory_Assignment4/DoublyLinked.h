/*Charlie Story and Alex Alvertos
Assignment 4 Registrar
4/4/2018
*/

#include <iostream>
#include "ListNode.h"

using namespace std;

template <class T>
class DoublyLinkedList {
    private:

    public:
        unsigned int size;
        ListNode<T> *front;
        ListNode<T> *back;

        DoublyLinkedList(); //Constructor
        ~DoublyLinkedList(); //Destructor

        void insertBack(T data);
        T removeFront();
        T getFront();

        void printList();
        void deletePos(T data); //I had this FREAKING AN INT
        bool isEmpty();
        unsigned int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    size = 0;
    front = NULL;
    back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {}

template <class T>
void DoublyLinkedList<T>::insertBack(T d) {
    ListNode<T> *node = new ListNode<T>(d);

    //Empty
    if(size == 0) {
        front = node;
    }
    //Not Empty
    else {
        back->next = node;
        node->prev = back;
    }

    back = node;
    ++size;
}

template <class T>
T DoublyLinkedList<T>::removeFront() {
    if(!isEmpty()) {
        ListNode<T> *node = front;
        //Only Node in List
        if(front->next == NULL) {
            front = NULL;
            back = NULL;
        }
        //More than One
        else {
            front->next->prev = NULL;
            front = front->next;
        }

        //node->next = NULL;

        T temp = node->data;

        delete node;
        --size;
        return temp;
    }
    else {
        return T();
    }
}

template <class T>
T DoublyLinkedList<T>::getFront() {
    return front->data;
}

template <class T>
void DoublyLinkedList<T>::printList() {
    ListNode<T> *curr = front;

    while(true) {
        if(curr->next == NULL) {
            break;
        }

        cout << curr->data << endl;
        curr = curr->next;
    }
}

template <class T>
void DoublyLinkedList<T>::deletePos(T pos) {
    int idx = 0;
    ListNode<T> *curr = front;
    ListNode<T> *prev = front;

    while(idx != pos) {
        prev = curr;
        curr = curr->next;
        ++idx;
    }

    prev->next = curr->next;
    curr->next->prev = prev;
    curr->next = NULL;
    curr->prev = NULL;
    curr->data = NULL;

    --size;
    delete curr;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty() {
    return(size == 0);
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize() {
    return size;
}
