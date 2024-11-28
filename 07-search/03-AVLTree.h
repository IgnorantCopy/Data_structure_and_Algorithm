//
// Created by Ignorant on 2024/11/21.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_03_AVLTREE_H
#define DATA_STRUCTURE_AND_ALGORITHM_03_AVLTREE_H

#include <iostream>
#include "02-binarySearchTree.h"
using namespace std;

template<class K>
struct AVLNode: public BSTNode<K> {
    int bf = 0;
    
    AVLNode() = default;
    explicit AVLNode(K data): BSTNode<K>(data) {}
};

template<class K>
class AVLTree:public BinarySearchTree<K> {
protected:
    int height(AVLNode<K> *node) const;
    bool insert(AVLNode<K> *&node, K &key);
    bool remove(AVLNode<K> *&node, K &key);
    
    void rotateL(AVLNode<K> *&node);    // 左单旋
    void rotateR(AVLNode<K> *&node);    // 右单旋
    void rotateLR(AVLNode<K> *&node);   // 先左后右双旋
    void rotateRL(AVLNode<K> *&node);   // 先右后左双旋
public:
    AVLTree() = default;
    explicit AVLTree(K key): BinarySearchTree<K>(key) {}
    
    [[nodiscard]] int height() const { return height(this->root); }
    AVLNode<K> *search(K key) { return BinarySearchTree<K>::search(key); }
    bool insert(K &key) { return insert(this->root, key); }
    bool remove(K &key) { return remove(this->root, key); }
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_03_AVLTREE_H
