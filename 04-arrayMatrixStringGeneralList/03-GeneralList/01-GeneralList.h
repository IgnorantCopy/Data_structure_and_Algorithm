//
// Created by Ignorant on 2024/10/26.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_01_GENERALLIST_H
#define DATA_STRUCTURE_AND_ALGORITHM_01_GENERALLIST_H

#include <iostream>
using namespace std;

template<class T>
class GeneralListNode {
    int utype = 0;      // 0: head; 1: data; 2: tail
    union {
        int ref;    // 0
        T value;    // 1
        GeneralListNode<T> *hlink;  // 2
    } info;
    GeneralListNode<T> *tlink = nullptr;
public:
    GeneralListNode() { info.ref = 0; }
    GeneralListNode(GeneralListNode<T> &other) {
        utype = other.utype;
        info = other.info;
        tlink = other.tlink;
    }
};

template<class T>
class GeneralList {
    GeneralListNode<T> *head = nullptr;
    GeneralListNode<T> *copy(GeneralListNode<T> *node);
    int length(GeneralListNode<T> *node);
    int depth(GeneralListNode<T> *node);
    bool equal(GeneralListNode<T> *node1, GeneralListNode<T> *node2);
    void remove(GeneralListNode<T> *node);
public:
    GeneralList();
    ~GeneralList();
    bool getHead(GeneralListNode<T> &node);
    bool getTail(GeneralList<T> &node);
    GeneralListNode<T> *getHead() const { return head; }
    void copy(const GeneralList<T> &other);
    int length();
    int depth();
};
#endif //DATA_STRUCTURE_AND_ALGORITHM_01_GENERALLIST_H
