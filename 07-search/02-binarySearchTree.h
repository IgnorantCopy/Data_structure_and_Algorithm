//
// Created by Ignorant on 2024/11/21.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_02_BINARYSEARCHTREE_H
#define DATA_STRUCTURE_AND_ALGORITHM_02_BINARYSEARCHTREE_H

#include <iostream>
using namespace std;

template<class K>
struct BSTNode {
    K data;
    BSTNode<K> *left = nullptr;
    BSTNode<K> *right = nullptr;
    
    BSTNode() = default;
    explicit BSTNode(K data): data(data) {}
    BSTNode(K data, BSTNode<K> *left, BSTNode<K> *right): data(data), left(left), right(right) {}
    ~BSTNode() = default;
    
    bool operator<(const BSTNode<K> &node) const { return data < node.data; }
    bool operator>(const BSTNode<K> &node) const { return data > node.data; }
    bool operator==(const BSTNode<K> &node) const { return data == node.data; }
};

template<class K>
class BinarySearchTree {
    BSTNode<K> *root = nullptr;
    K ref;      // stop flag
    BSTNode<K> search(BSTNode<K> *node, K key);
    void makeEmpty(BSTNode<K> *&node);
    bool insert(BSTNode<K> *&node, K &key);
    bool remove(BSTNode<K> *&node, K key);
public:
    BinarySearchTree() = default;
    explicit BinarySearchTree(K key);
    ~BinarySearchTree() { makeEmpty(); }
    
    BinarySearchTree<K>& operator=(const BinarySearchTree<K> &other);
    bool search(const K key) const { return search(root, key) != nullptr; }
    void makeEmpty() { makeEmpty(root); }
    bool insert(const K &key) { return insert(root, key); }
    bool remove(const K key) { return remove(root, key); }
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_02_BINARYSEARCHTREE_H
