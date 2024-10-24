//
// Created by Ignorant on 2024/10/10.
//

#include "01-queue.h"

template<class T>
void Queue<T>::makeEmpty() {
    Node<T> *current = head;
    while (current != nullptr) {
        Node<T> *temp = current;
        current = current->next;
        delete temp;
    }
    size = 0;
}

template<class T>
void Queue<T>::push(T data) {
    Node<T> *newNode = new Node(data);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template<class T>
bool Queue<T>::pop(T &data) {
    if (isEmpty()) {
        return false;
    }
    data = head->data;
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    return true;
}