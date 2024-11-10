//
// Created by Ignorant on 2024/11/7.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_03_TREE_H
#define DATA_STRUCTURE_AND_ALGORITHM_03_TREE_H

#include <iostream>
#include <queue>

using namespace std;

template<class T>
class TreeNode {
    T data = 0;
    TreeNode<T> *leftChild = nullptr;
    TreeNode<T> *nextSibling = nullptr;
public:
    explicit TreeNode(T data = 0, TreeNode<T> *leftChild = nullptr, TreeNode<T> *nextSibling = nullptr):
    data(data), leftChild(leftChild), nextSibling(nextSibling) {}
};

template<class T>
class Tree {
    TreeNode<T> *root = nullptr;
    TreeNode<T> *current = nullptr;
    
    bool find(TreeNode<T> *subtree, T data);
    void removeSubTree(TreeNode<T> *subtree);
    bool findParent(TreeNode<T> *subtree, TreeNode<T> *child);
public:
    Tree() = default;
    ~Tree() { removeSubTree(root); }
    bool setRoot();
    bool isEmpty() { return root == nullptr; }
    bool setFirstChild();
    bool setNextSibling();
    bool setParent();
    bool find(T data);
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_03_TREE_H
