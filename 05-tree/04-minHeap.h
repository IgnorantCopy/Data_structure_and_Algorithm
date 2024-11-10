//
// Created by Ignorant on 2024/11/8.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_04_MINHEAP_H
#define DATA_STRUCTURE_AND_ALGORITHM_04_MINHEAP_H

#include <iostream>

using namespace std;

const int defaultCapacity = 100;

template<class T, class E>
class MinPriorityQueue {
public:
    virtual bool insert(E &e) = 0;
    virtual bool remove(E &e) = 0;
};

template<class T, class E>
class MinHeap: public MinPriorityQueue<T, E> {
    E *heap;
    int size = 0;
    int capacity = defaultCapacity;
    void shiftUp(int start);
    void shiftDown(int start, int end);
public:
    MinHeap() = default;
    explicit MinHeap(int cap);
    MinHeap(E *arr, int n);
    ~MinHeap() { delete[] heap; }
    bool insert(E &e);
    bool remove(E &e);
    [[nodiscard]] bool isEmpty() const { return size == 0; }
    [[nodiscard]] bool isFull() const { return size == capacity; }
    void makeEmpty() { size = 0; }
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_04_MINHEAP_H
