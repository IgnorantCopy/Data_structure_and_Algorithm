//
// Created by Ignorant on 2024/9/19.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_CIRCLELIST_H
#define DATA_STRUCTURE_AND_ALGORITHM_CIRCLELIST_H

class Node {
    friend class CircleList;
private:
    int data;
    Node *next;
public:
    Node(): data(0), next(nullptr) {}
    explicit Node(int data, Node *next = nullptr): data(data), next(next) {}
    ~Node() = default;
};

class CircleList {
private:
    Node *head = nullptr;
    int size = 0;
public:
    CircleList() = default;
    ~CircleList() { clear(); }
    
    void clear();
    Node *search(int data);
    Node *locate(int index);
    void add(int data);
    void remove(int index);
    bool isEmpty() const { return size == 0; }
    int length() const { return size; }
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_CIRCLELIST_H
