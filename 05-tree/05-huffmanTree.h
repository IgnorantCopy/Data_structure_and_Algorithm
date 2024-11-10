//
// Created by Ignorant on 2024/11/10.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_05_HUFFMANTREE_H
#define DATA_STRUCTURE_AND_ALGORITHM_05_HUFFMANTREE_H

#include <iostream>
using namespace std;

const int defaultSize = 100;

template<class T, class E>
class HuffmanNode {
    E data;
    HuffmanNode<T, E> *parent = nullptr;
    HuffmanNode<T, E> *leftChild = nullptr;
    HuffmanNode<T, E> *rightChild = nullptr;
public:
    HuffmanNode() = default;
    explicit HuffmanNode(E data, HuffmanNode<T, E> *parent = nullptr, HuffmanNode<T, E> *left = nullptr, HuffmanNode<T, E> *right = nullptr):
            data(data), parent(parent), leftChild(left), rightChild(right) {}
};

template<class T, class E>
class HuffmanTree {
protected:
    HuffmanNode<T, E> *root = nullptr;
    void deleteTree(HuffmanNode<T, E> *node);
    void mergeTree(HuffmanNode<T, E> &node1, HuffmanNode<T, E> &node2, HuffmanNode<T, E> *&parent);
public:
    HuffmanTree(E *weight, int size);
    ~HuffmanTree() { deleteTree(root); }
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_05_HUFFMANTREE_H
