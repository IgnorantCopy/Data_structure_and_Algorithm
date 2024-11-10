//
// Created by Ignorant on 2024/11/4.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_02_THREADTREE_H
#define DATA_STRUCTURE_AND_ALGORITHM_02_THREADTREE_H

#include <iostream>

using namespace std;

template<class T> class ThreadTree;

template<class T>
class ThreadNode {
    int ltag = 0;
    int rtag = 0;
    ThreadNode<T> *left = nullptr;
    ThreadNode<T> *right = nullptr;
    T data;
    friend class ThreadTree<T>;
public:
    ThreadNode(const T value): data(value) {}
};

template<class T>
class ThreadTree {
protected:
    ThreadNode<T> *root = nullptr;
    
    void createInorderThread(ThreadNode<T> *current, ThreadNode<T> *&prev);
    ThreadNode<T> *parent(ThreadNode<T> *t);
public:
    ThreadTree() = default;
    void createInorderThread();
    ThreadNode<T> *first(ThreadNode<T> *current);
    ThreadNode<T> *last(ThreadNode<T> *current);
    ThreadNode<T> *next(ThreadNode<T> *current);
    ThreadNode<T> *prev(ThreadNode<T> *current);
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_02_THREADTREE_H
