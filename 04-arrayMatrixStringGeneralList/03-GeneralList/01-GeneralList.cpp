//
// Created by Ignorant on 2024/10/26.
//

#include "01-GeneralList.h"

template<class T>
GeneralList<T>::GeneralList() {
    head = new GeneralListNode<T>;
}

template<class T>
bool GeneralList<T>::getHead(GeneralListNode<T> &node) {
    if (head->tlink == nullptr) {
        return false;
    }
    node.utype = head->tlink->utype;
    node.info = head->tlink->info;
    return true;
}

template<class T>
bool GeneralList<T>::getTail(GeneralList<T> &node) {
    if (head->tlink == nullptr) {
        return false;
    }
    node.head->utype = 0;
    node.head->info.ref = 0;
    node.head->tlink = copy(head->tlink->tlink);
    return true;
}

template<class T>
void GeneralList<T>::copy(const GeneralList<T> &other) {
    head = copy(other.head);
}

template<class T>
GeneralListNode<T> *GeneralList<T>::copy(GeneralListNode<T> *node) {
    GeneralListNode<T> *newNode = nullptr;
    if (node != nullptr) {
        newNode = new GeneralListNode<T>;
        newNode->utype = node->utype;
        switch (node->utype) {
            case 0:
                newNode->info.ref = node->info.ref;
                break;
            case 1:
                newNode->info.value = node->info.value;
                break;
            case 2:
                newNode->info.hlink = copy(node->info.hlink);
                break;
            default:
                break;
        }
        newNode->tlink = copy(node->tlink);
    }
    return newNode;
}

template<class T>
int GeneralList<T>::depth() {
    return depth(head);
}

template<class T>
int GeneralList<T>::depth(GeneralListNode<T> *node) {
    if (node->tlink == nullptr) {
        return 1;
    }
    GeneralListNode<T> *temp = node->tlink;
    int maxDepth = 0;
    while (temp != nullptr) {
        if (temp->utype == 2) {
            int depth = depth(temp->info.hlink);
            if (depth > maxDepth) {
                maxDepth = depth;
            }
        }
        temp = temp->tlink;
    }
    return maxDepth + 1;
}

template<class T>
GeneralList<T>::~GeneralList() {
    remove(head);
}

template<class T>
void GeneralList<T>::remove(GeneralListNode<T> *node) {
    node->info.ref--;
    if (node->info.ref <= 0) {
        GeneralListNode<T> *temp;
        while (node->tlink != nullptr) {
            temp = node->tlink;
            if (temp->utype == 2) {
                remove(temp->info.hlink);
                if (temp->info.hlink->info.ref <= 0) {
                    delete temp->info.hlink;
                }
            }
            node->tlink = temp->tlink;
            delete temp;
        }
    }
}

template<class T>
int GeneralList<T>::length() {
    return length(head);
}

template<class T>
int GeneralList<T>::length(GeneralListNode<T> *node) {
    int result = 0;
    while (node != nullptr) {
        result++;
        node = node->tlink;
    }
    return result;
}

template<class T>
bool GeneralList<T>::equal(GeneralListNode<T> *node1, GeneralListNode<T> *node2) {
    if (node1 == nullptr && node2 == nullptr) {
        return true;
    }
    if (node1 == nullptr || node2 == nullptr) {
        return false;
    }
    if (node1->utype != node2->utype) {
        return false;
    }
    switch (node1->utype) {
        case 0:
            return node1->info.ref == node2->info.ref;
        case 1:
            return node1->info.value == node2->info.value;
        case 2:
            return equal(node1->info.hlink, node2->info.hlink);
        default:
            return false;
    }
}