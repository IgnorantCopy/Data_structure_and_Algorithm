//
// Created by Ignorant on 2024/11/1.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_01_BINARYTREE_H
#define DATA_STRUCTURE_AND_ALGORITHM_01_BINARYTREE_H

#include <iostream>
using namespace std;

template<class T> class BinaryTree;

template<class T>
class BinaryTreeNode {
    T data;
    BinaryTreeNode<T> *parent = nullptr;
    BinaryTreeNode<T> *leftChild = nullptr;
    BinaryTreeNode<T> *rightChild = nullptr;
    friend class BinaryTree<T>;
public:
    BinaryTreeNode() = default;
    explicit BinaryTreeNode(const T& data): data(data) {}
    BinaryTreeNode(const T& data, BinaryTreeNode<T>* parent): data(data), parent(parent) {}
    BinaryTreeNode(const T& data, BinaryTreeNode<T>* parent, BinaryTreeNode<T>* leftChild, BinaryTreeNode<T>* rightChild):
            data(data), parent(parent), leftChild(leftChild), rightChild(rightChild) {}
    BinaryTreeNode<T> *getLeftChild() const { return leftChild; }
    BinaryTreeNode<T> *getRightChild() const { return rightChild; }
    BinaryTreeNode<T> *getParent() const { return parent; }
    T getData() const { return data; }
};

template<class T>
class BinaryTree {
protected:
    BinaryTreeNode<T> *root = nullptr;
    T refData;
    bool insert(BinaryTreeNode<T>* subTree, const T& data);
    void remove(BinaryTreeNode<T>* subTree);
    bool find(BinaryTreeNode<T>* subTree, const T& data);
    BinaryTreeNode<T>* find(BinaryTreeNode<T>* subTree, const T& data) const;
    BinaryTreeNode<T>* copy(BinaryTreeNode<T> *subTree);
    int depth(BinaryTreeNode<T>* subTree);
    int size(BinaryTreeNode<T>* subTree);
    void preOrder(BinaryTreeNode<T>* subTree, void (*visit)(BinaryTreeNode<T>* node));  // 前序遍历
    void inOrder(BinaryTreeNode<T>* subTree, void (*visit)(BinaryTreeNode<T>* node));   // 中序遍历
    void postOrder(BinaryTreeNode<T>* subTree, void (*visit)(BinaryTreeNode<T>* node)); // 后序遍历
    void createTree(istream& in, BinaryTreeNode<T>*& subTree);
public:
    BinaryTree() = default;
    explicit BinaryTree(const T& data): refData(data) {}
    BinaryTree(BinaryTree<T> &other) { root = copy(other.root); }
    ~BinaryTree() { remove(root); }
    [[nodiscard]] bool isEmpty() const { return root == nullptr; }
    int height() { return depth(root); }
    int size() { return size(root); }
    BinaryTreeNode<T>* getRoot() const { return root; }
    void preOrder(void (*visit)(BinaryTreeNode<T>* node)) { preOrder(root, visit); }
    void inOrder(void (*visit)(BinaryTreeNode<T>* node)) { inOrder(root, visit); }
    void postOrder(void (*visit)(BinaryTreeNode<T>* node)) { postOrder(root, visit); }
    void levelOrder(void (*visit)(BinaryTreeNode<T>* node));    // 层序遍历
    int insert(const T& data);
    BinaryTreeNode<T>* find(const T& data) const { return find(root, data); }
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_01_BINARYTREE_H
