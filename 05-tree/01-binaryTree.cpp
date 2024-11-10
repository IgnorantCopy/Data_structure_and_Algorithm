//
// Created by Ignorant on 2024/11/1.
//

#include "01-binaryTree.h"
#include <queue>
#include <stack>


template<class T>
bool BinaryTree<T>::insert(BinaryTreeNode<T> *subTree, const T &data) {
    if (nullptr == subTree || nullptr != subTree->rightChild) {
        return false;
    }
    if (nullptr == subTree->leftChild) {
        subTree->leftChild = new BinaryTreeNode<T>(data, subTree);
    } else {
        subTree->rightChild = new BinaryTreeNode<T>(data, subTree);
    }
    return true;
}

template<class T>
void BinaryTree<T>::remove(BinaryTreeNode<T> *subTree) {
    if (nullptr != subTree) {
        remove(subTree->leftChild);
        remove(subTree->rightChild);
        delete subTree;
    }
}

template<class T>
bool BinaryTree<T>::find(BinaryTreeNode<T> *subTree, const T &data) {
    if (nullptr == subTree) {
        return false;
    }
    if (data == subTree->data) {
        return true;
    }
    return find(subTree->leftChild, data) || find(subTree->rightChild, data);
}

template<class T>
BinaryTreeNode<T> *BinaryTree<T>::find(BinaryTreeNode<T> *subTree, const T &data) const {
    if (nullptr == subTree) {
        return nullptr;
    }
    if (data == subTree->data) {
        return subTree;
    }
    BinaryTreeNode<T> *left = find(subTree->leftChild, data);
    if (nullptr != left) {
        return left;
    }
    return find(subTree->rightChild, data);
}

template<class T>
BinaryTreeNode<T> *BinaryTree<T>::copy(BinaryTreeNode<T> *subTree) {
    if (nullptr == subTree) {
        return nullptr;
    }
    auto *newRoot = new BinaryTreeNode<T>(subTree->data);
    newRoot->leftChild = copy(subTree->leftChild);
    newRoot->rightChild = copy(subTree->rightChild);
    return newRoot;
}

template<class T>
int BinaryTree<T>::depth(BinaryTreeNode<T> *subTree) {
    if (nullptr == subTree) {
        return 0;
    }
    int leftDepth = depth(subTree->leftChild);
    int rightDepth = depth(subTree->rightChild);
    return max(leftDepth, rightDepth) + 1;
}

template<class T>
int BinaryTree<T>::size(BinaryTreeNode<T>* subTree) {
    if (nullptr == subTree) {
        return 0;
    }
    return 1 + size(subTree->leftChild) + size(subTree->rightChild);
}

template<class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> *subTree, void (*visit)(BinaryTreeNode<T> *)) {
    if (nullptr == subTree) {
        return;
    }
    visit(subTree);
    preOrder(subTree->leftChild, visit);
    preOrder(subTree->rightChild, visit);
}

// without recursion
template<class T>
void preOrder(BinaryTreeNode<int> *subTree, void (*visit)(BinaryTreeNode<int> *)) {
    stack<BinaryTreeNode<T>*> s;
    s.push(nullptr);
    while (subTree) {
        visit(subTree);
        if (nullptr != subTree->getRightChild()) {
            s.push(subTree->getRightChild());
        }
        if (nullptr != subTree->getLeftChild()) {
            subTree = subTree->getLeftChild();
        } else {
            s.pop();
        }
    }
}

template<class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> *subTree, void (*visit)(BinaryTreeNode<T> *)) {
    if (nullptr == subTree) {
        return;
    }
    inOrder(subTree->leftChild, visit);
    visit(subTree);
    inOrder(subTree->rightChild, visit);
}

// without recursion
template<class T>
void inOrder(BinaryTreeNode<int> *subTree, void (*visit)(BinaryTreeNode<int> *)) {
    stack<BinaryTreeNode<T>*> s;
    do {
        while (subTree) {
            s.push(subTree);
            subTree = subTree->getLeftChild();
        }
        if (!s.empty()) {
            visit(s.top());
            s.pop();
            subTree = subTree->getRightChild();
        }
    } while (subTree || !s.empty());
}

template<class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *subTree, void (*visit)(BinaryTreeNode<T> *)) {
    if (nullptr == subTree) {
        return;
    }
    postOrder(subTree->leftChild, visit);
    postOrder(subTree->rightChild, visit);
    visit(subTree);
}

// without recursion
template<class T>
struct stackNode {
    BinaryTreeNode<T> *ptr;
    enum tag { LEFT, RIGHT };
    explicit stackNode(BinaryTreeNode<T> *ptr = nullptr): ptr(ptr), tag(LEFT) {}
};

template<class T>
void postOrder(BinaryTreeNode<int> *subTree, void (*visit)(BinaryTreeNode<int> *)) {
    stack<stackNode<T>> s;
    stackNode<T> node;
    do {
        while (subTree) {
            node.ptr = subTree;
            node.tag = stackNode<T>::LEFT;
            s.push(node);
            subTree = subTree->getLeftChild();
        }
        bool isContinue = true;
        while (!s.empty() && isContinue) {
            node = s.top();
            s.pop();
            subTree = node.ptr;
            switch (node.tag) {
                case stackNode<T>::LEFT:
                    node.tag = stackNode<T>::RIGHT;
                    s.push(node);
                    subTree = subTree->getRightChild();
                    isContinue = false;
                    break;
                case stackNode<T>::RIGHT:
                    visit(subTree);
                    break;
            }
        }
    } while (!s.empty());
}

template<class T>
void BinaryTree<T>::levelOrder(void (*visit)(BinaryTreeNode<T> *)) {
    if (nullptr == root) {
        return;
    }
    queue<BinaryTreeNode<T> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<T> *node = q.front();
        q.pop();
        visit(node);
        if (nullptr != node->leftChild) {
            q.push(node->leftChild);
        }
        if (nullptr != node->rightChild) {
            q.push(node->rightChild);
        }
    }
}

template<class T>
void BinaryTree<T>::createTree(istream &in, BinaryTreeNode<T> *&subTree) {
    T data;
    if (!in.eof()) {
        in >> data;
        if (data != refData) {
            subTree = new BinaryTreeNode<T>(data);
            createTree(in, subTree->leftChild);
            createTree(in, subTree->rightChild);
        } else {
            subTree = nullptr;
        }
    }
}