//
// Created by Ignorant on 2024/9/26.
//

#include "01-stack.h"
#include <iostream>

template<class T>
void Stack<T>::makeEmpty() {
    while (!isEmpty()) {
        pop();
    }
}

template<class T>
void Stack<T>::push(T data) {
    if (isEmpty()) {
        top = new Node<T>(data);
    } else {
        auto *newNode = new Node<T>(data);
        newNode->next = top;
        top = newNode;
    }
    len++;
}

template<class T>
bool Stack<T>::pop(T &data) {
    if (isEmpty()) {
        return false;
    }
    data = top->data;
    auto *temp = top;
    top = top->next;
    delete temp;
    len--;
    return true;
}

template<class T>
bool Stack<T>::getTop(T &data) {
    if (isEmpty()) {
        return false;
    }
    data = top->data;
    return true;
}