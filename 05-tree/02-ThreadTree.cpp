//
// Created by Ignorant on 2024/11/4.
//

#include "02-ThreadTree.h"

template<class T>
void ThreadTree<T>::createInorderThread() {
    ThreadNode<T> *prev = nullptr;
    if (root) {
        createInorderThread(root, prev);
        prev->rtag = 1;
    }
}

template<class T>
void ThreadTree<T>::createInorderThread(ThreadNode<T> *current, ThreadNode<T> *&prev) {
    if (!current) {
        return;
    }
    createInorderThread(current->left, prev);
    if (current->left == nullptr) {
        current->left = prev;
        current->ltag = 1;
    }
    if (prev && prev->right == nullptr) {
        prev->right = current;
        prev->rtag = 1;
    }
    prev = current;
    createInorderThread(current->right, prev);
}

template<class T>
ThreadNode<T> *ThreadTree<T>::parent(ThreadNode<T> *t) {
    if (t == nullptr || t == root) {
        return nullptr;
    }
    if (t->ltag == 1) {
        return t->left;
    }
    ThreadNode<T> *current = t->left;
    while (current && current->rtag == 0) {
        current = current->right;
    }
    return current;
}

template<class T>
ThreadNode<T> *ThreadTree<T>::first(ThreadNode<T> *current) {
    if (current == nullptr) {
        return nullptr;
    }
    while (current->left) {
        current = current->left;
    }
    return current;
}

template<class T>
ThreadNode<T> *ThreadTree<T>::last(ThreadNode<T> *current) {
    if (current == nullptr) {
        return nullptr;
    }
    while (current->right) {
        current = current->right;
    }
    return current;
}

template<class T>
ThreadNode<T> *ThreadTree<T>::next(ThreadNode<T> *current) {
    if (current == nullptr) {
        return nullptr;
    }
    if (current->rtag == 1) {
        return nullptr;
    }
    if (current->right) {
        return first(current->right);
    }
    ThreadNode<T> *parent = parent(current);
    while (parent && current == parent->right) {
        current = parent;
        parent = parent(parent);
    }
    return parent;
}

template<class T>
ThreadNode<T> *ThreadTree<T>::prev(ThreadNode<T> *current) {
    if (current == nullptr) {
        return nullptr;
    }
    if (current->ltag == 1) {
        return nullptr;
    }
    if (current->left) {
        return last(current->left);
    }
    ThreadNode<T> *parent = parent(current);
    while (parent && current == parent->left) {
        current = parent;
        parent = parent(parent);
    }
    return parent;
}
