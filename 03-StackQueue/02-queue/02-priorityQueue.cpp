//
// Created by Ignorant on 2024/10/24.
//

#include "02-priorityQueue.h"
using namespace std;

template<class E>
void PriorityQueue<E>::adjust() {
    E temp = elements[size - 1];
    int i = size - 2;
    for (; i >= 0; i--) {
        if (elements[i] <= temp) {
            break;
        }
        elements[i + 1] = elements[i];
    }
    elements[i + 1] = temp;
}

template<class E>
PriorityQueue<E>::PriorityQueue(int size_): capacity(size_) {
    elements = new E[capacity];
}

template<class E>
bool PriorityQueue<E>::insert(E ele) {
    if (isFull()) {
        return false;
    }
    elements[size++] = ele;
    adjust();
    return true;
}

template<class E>
bool PriorityQueue<E>::remove(E &ele) {
    if (isEmpty()) {
        return false;
    }
    ele = elements[0];
    for (int i = 0; i < size - 1; i++) {
        elements[i] = elements[i + 1];
    }
    size--;
    return true;
}

template<class E>
bool PriorityQueue<E>::getFront(E &ele) {
    if (isEmpty()) {
        return false;
    }
    ele = elements[0];
    return true;
}