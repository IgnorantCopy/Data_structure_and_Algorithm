//
// Created by Ignorant on 2024/11/7.
//

#include "03-tree.h"

template<class T>
bool Tree<T>::setRoot() {
    if (root == nullptr) {
        current = nullptr;
        return false;
    }
    current = root;
    return true;
}

template<class T>
bool Tree<T>::setParent() {
    if (current == nullptr || current == root) {
        current = nullptr;
        return false;
    }
    TreeNode<T> *parent = current;
    return findParent(root, parent);
}

template<class T>
bool Tree<T>::findParent(TreeNode<T> *subtree, TreeNode<T> *child) {
    TreeNode<T> *temp = subtree->leftChild;
    while (temp != nullptr && temp != child) {
        bool found = findParent(temp, child);
        if (found) {
            return true;
        }
        temp = temp->nextSibling;
    }
    if (temp != nullptr && temp == child) {
        current = subtree;
        return true;
    }
    current = nullptr;
    return false;
}

template<class T>
bool Tree<T>::setFirstChild() {
    if (current && current->leftChild) {
        current = current->leftChild;
        return true;
    }
    current = nullptr;
    return false;
}

template<class T>
bool Tree<T>::setNextSibling() {
    if (current && current->nextSibling) {
        current = current->nextSibling;
        return true;
    }
    current = nullptr;
    return false;
}

template<class T>
bool Tree<T>::find(T data) {
    return find(root, data);
}

template<class T>
bool Tree<T>::find(TreeNode<T> *subtree, T data) {
    if (subtree == nullptr) {
        return false;
    }
    TreeNode<T> *temp = subtree->leftChild;
    while (temp != nullptr && temp->data != data) {
        bool found = find(temp, data);
        if (found) {
            return true;
        }
        temp = temp->nextSibling;
    }
    if (temp != nullptr && temp->data == data) {
        current = temp;
        return true;
    }
    current = nullptr;
    return false;
}

template<class T>
void Tree<T>::removeSubTree(TreeNode<T> *subtree) {
    if (subtree == nullptr) {
        return;
    }
    removeSubTree(subtree->leftChild);
    removeSubTree(subtree->nextSibling);
    delete subtree;
}
