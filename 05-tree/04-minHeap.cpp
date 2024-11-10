//
// Created by Ignorant on 2024/11/8.
//

#include "04-minHeap.h"

template<class T, class E>
MinHeap<T, E>::MinHeap(int cap) {
    capacity = max(defaultCapacity, cap);
    heap = new E[capacity];
    size = 0;
}

template<class T, class E>
MinHeap<T, E>::MinHeap(E *arr, int n) {
    capacity = max(defaultCapacity, n);
    heap = new E[capacity];
    size = n;
    for (int i = 0; i < n; i++) {
        heap[i] = arr[i];
    }
    int pos = n / 2 - 1;
    while (pos >= 0) {
        shiftDown(pos, size - 1);
        pos--;
    }
}

template<class T, class E>
void MinHeap<T, E>::shiftDown(int start, int end) {
    int pos = start;
    int left = 2 * pos + 1;
    E temp = heap[pos];
    while (left <= end) {
        if (left < end && heap[left] > heap[left + 1]) {
            left++;
        }
        if (temp <= heap[left]) {
            break;
        }
        heap[pos] = heap[left];
        pos = left;
        left = 2 * pos + 1;
    }
    heap[pos] = temp;
}

template<class T, class E>
bool MinHeap<T, E>::insert(E &e) {
    if (isFull()) {
        return false;
    }
    heap[size] = e;
    shiftUp(size);
    size++;
    return true;
}

template<class T, class E>
void MinHeap<T, E>::shiftUp(int start) {
    int pos = start;
    int parent = (pos - 1) / 2;
    E temp = heap[pos];
    while (pos > 0 && temp < heap[parent]) {
        heap[pos] = heap[parent];
        pos = parent;
        parent = (pos - 1) / 2;
    }
    heap[pos] = temp;
}

template<class T, class E>
bool MinHeap<T, E>::remove(E &e) {
    if (isEmpty()) {
        return false;
    }
    e = heap[0];
    heap[0] = heap[--size];
    shiftDown(0, size - 1);
    return true;
}
