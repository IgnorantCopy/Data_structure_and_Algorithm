//
// Created by Ignorant on 2024/9/19.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_DOUBLELINKEDLIST_H
#define DATA_STRUCTURE_AND_ALGORITHM_DOUBLELINKEDLIST_H

class Node {
    friend class DoubleLinkedList;
private:
    int data;
    Node *previous;
    Node *next;
public:
    Node() = default;
    Node(int data, Node *previous = nullptr, Node *next = nullptr): data(data), previous(previous), next(next) {}
    ~Node() = default;
};

class DoubleLinkedList {
private:
    Node *head;
    Node *tail;
    int size;
public:
    DoubleLinkedList() = default;
    ~DoubleLinkedList() { clear(); }
    
    void clear();
    int length() const { return size; }
    Node *search(int data);
    Node *locate(int index);
    bool insert(int data, int index);
    bool remove(int data, int index);
    bool isEmpty() const { return size == 0; }
    void sort();
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_DOUBLELINKEDLIST_H
