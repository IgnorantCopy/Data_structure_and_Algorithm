//
// Created by Ignorant on 2024/9/19.
//

#include <iostream>
#include "../inc/linkedList.h"
using namespace std;


template<class T>
LinkedList<T>::LinkedList(LinkedList<T> &other) {
    this->clear();
    Node<T> *current = other.head;
    this->head = new Node<T>(current->data);
    current = current->next;
    while (current != nullptr) {
        this->insert(this->len(), current->data);
        current = current->next;
    }
}

template<class T>
void LinkedList<T>::clear() {
    Node<T> *current = head;
    while (current != nullptr) {
        Node<T> *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    len = 0;
}

template<class T>
Node<T> *LinkedList<T>::search(T data) {
    Node<T> *current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template<class T>
Node<T> *LinkedList<T>::locate(int index) {
    if (index < 0 || index >= len) {
        cerr << "Error: index out of range." << endl;
        return nullptr;
    }
    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

template<class T>
T *LinkedList<T>::getData(int index) {
    Node<T> *node = locate(index);
    if (node != nullptr) {
        return &node->data;
    }
    return nullptr;
}

template<class T>
void LinkedList<T>::setData(int index, T &data) {
    Node<T> *node = locate(index);
    if (node != nullptr) {
        node->data = data;
    }
}

template<class T>
bool LinkedList<T>::insert(int index, T &data) {
    if (index < 0 || index > len) {
        cerr << "Error: index out of range." << endl;
        return false;
    }
    auto *node = new Node<T>(data);
    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    len++;
    return true;
}

template<class T>
bool LinkedList<T>::remove(int index, T &data) {
    if (index < 0 || index >= len) {
        cerr << "Error: index out of range." << endl;
        return false;
    }
    Node<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    Node<T> *temp = current->next;
    current->next = temp->next;
    data = temp->data;
    delete temp;
    len--;
    return true;
}

template<class T>
Node<T>* LinkedList<T>::reverse(Node<T> *head) {
    Node<T> *current = head;
    while (current != nullptr) {
        this->insert(0, current->data);
        current = current->next;
    }
    return this->head;
}

template<class T>
void LinkedList<T>::sort() {
    Node<T> *current = head;
    while (current != nullptr) {
        Node<T> *temp = current->next;
        while (temp != nullptr) {
            if (current->data > temp->data) {
                T tempData = current->data;
                current->data = temp->data;
                temp->data = tempData;
            }
            temp = temp->next;
        }
        current = current->next;
    }
}