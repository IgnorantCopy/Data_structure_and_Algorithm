//
// Created by Ignorant on 2024/10/10.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_01_QUEUE_H
#define DATA_STRUCTURE_AND_ALGORITHM_01_QUEUE_H

#include <iostream>

template<class T> class Queue;

template<class T>
class Node {
    friend class Queue<T>;
    T data = 0;
    Node *next = nullptr;
public:
    Node(int data): data(data) {}
};

template<class T>
class Queue {
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    size_t size = 0;
    
public:
    Queue() = default;
    ~Queue() { makeEmpty(); };
    
    void makeEmpty();
    bool isEmpty() const { return size == 0; }
    size_t length() const { return size; }
    void push(T data);
    bool pop(T &data);
    T top() const { return head->data; }
    void replace(T data) { head->data = data; }
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_01_QUEUE_H
