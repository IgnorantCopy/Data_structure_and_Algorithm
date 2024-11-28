//
// Created by Ignorant on 2024/11/21.
//

#include "02-binarySearchTree.h"

template<class K>
BSTNode<K> BinarySearchTree<K>::search(BSTNode<K> *node, K key) {
    if (node == nullptr || node->key == key) {
        return node;
    }
    if (key < node->key) {
        return search(node->left, key);
    }
    return search(node->right, key);
}

template<class K>
bool BinarySearchTree<K>::insert(BSTNode<K> *&node, K &key) {
    if (node == nullptr) {
        node = new BSTNode<K>(key);
        return true;
    }
    if (key < node->key) {
        return insert(node->left, key);
    }
    if (key > node->key) {
        return insert(node->right, key);
    }
    return false;
}

template<class K>
BinarySearchTree<K>::BinarySearchTree(K key) {
    this->ref = key;
    K in;
    cin >> in;
    while (in != this->ref) {
        insert(this->root, in);
        cin >> in;
    }
}

template<class K>
bool BinarySearchTree<K>::remove(BSTNode<K> *&node, K key) {
    BSTNode<K> *temp;
    if (node == nullptr) {
        return false;
    }
    if (key < node->key) {
        return remove(node->left, key);
    }
    if (key > node->key) {
        return remove(node->right, key);
    }
    if (node->left != nullptr && node->right != nullptr) {
        temp = node->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        node->key = temp->key;
        return remove(node->right, temp->key);
    }
    temp = node;
    node = (node->left != nullptr) ? node->left : node->right;
    delete temp;
    return true;
}

template<class K>
void BinarySearchTree<K>::makeEmpty(BSTNode<K> *&node) {
    if (node == nullptr) {
        return;
    }
    makeEmpty(node->left);
    makeEmpty(node->right);
    delete node;
    node = nullptr;
}

template<class K>
BinarySearchTree<K> &BinarySearchTree<K>::operator=(const BinarySearchTree<K> &other) {
    if (this == &other) {
        return *this;
    }
    makeEmpty(this->root);
    this->root = copy(other.root);
    this->ref = other.ref;
    return *this;
}
