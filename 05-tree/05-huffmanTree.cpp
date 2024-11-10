//
// Created by Ignorant on 2024/11/10.
//

#include "05-huffmanTree.h"
#include "04-minHeap.h"

template<class T, class E>
HuffmanTree<T, E>::HuffmanTree(E *weight, int size) {
    MinHeap<T, E> heap;
    HuffmanNode<T, E> *parent;
    HuffmanNode<T, E> &first();
    HuffmanNode<T, E> &second();
    auto *nodeList = new HuffmanNode<T, E>[size];
    for (int i = 0; i < size; i++) {
        nodeList[i].data = weight[i + 1];
        nodeList[i].leftChild = nullptr;
        nodeList[i].rightChild = nullptr;
        nodeList[i].parent = nullptr;
        heap.insert(nodeList[i]);
    }
    for (int i = 0; i < size - 1; i++) {
        heap.remove(first);
        heap.remove(second);
        mergeTree(first, second, parent);
        heap.insert(*parent);
        root = parent;
    }
}

template<class T, class E>
void HuffmanTree<T, E>::mergeTree(HuffmanNode<T, E> &node1, HuffmanNode<T, E> &node2, HuffmanNode<T, E> *&parent) {
    parent = new HuffmanNode<T, E>;
    parent->leftChild = &node1;
    parent->rightChild = &node2;
    parent->data = node1.data + node2.data;
    node1.parent = parent;
    node2.parent = parent;
}

template<class T, class E>
void HuffmanTree<T, E>::deleteTree(HuffmanNode<T, E> *node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    delete node;
}
