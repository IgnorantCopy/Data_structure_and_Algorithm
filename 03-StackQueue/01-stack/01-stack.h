//
// Created by Ignorant on 2024/9/26.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_01_STACK_H
#define DATA_STRUCTURE_AND_ALGORITHM_01_STACK_H

template<class T> class Stack;

template<class T>
class Node {
    friend class Stack<T>;
    T data;
    Node<T> *next = nullptr;
public:
    explicit Node(T data): data(data) {}
};

template<class T>
class Stack {
private:
    Node<T>* top = nullptr;
    int len = 0;
public:
    Stack() = default;
    ~Stack() { makeEmpty(); }
    
    bool isEmpty() const { return top == nullptr; }
    int length() const { return len; }
    void makeEmpty();
    void push(T data);
    bool pop(T &data);
    bool getTop(T &data);
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_01_STACK_H
