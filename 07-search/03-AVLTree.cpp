//
// Created by Ignorant on 2024/11/21.
//

#include <queue>
#include "03-AVLTree.h"

template<class K>
void AVLTree<K>::rotateL(AVLNode<K> *&node) {
    AVLNode<K> *top = node;
    node = top->right;
    top->right = node->left;
    node->left = top;
    node->bf = top->bf = 0;
}

template<class K>
void AVLTree<K>::rotateR(AVLNode<K> *&node) {
    AVLNode<K> *top = node;
    node = top->left;
    top->left = node->right;
    node->right = top;
    node->bf = top->bf = 0;
}

template<class K>
void AVLTree<K>::rotateLR(AVLNode<K> *&node) {
    AVLNode<K> *subR = node;
    AVLNode<K> *subL = node->left;
    node = subL->right;
    subL->right = node->left;
    node->left = subL;
    if (node->bf <= 0) {
        subL->bf = 0;
    } else {
        subL->bf = -1;
    }
    subR->left = node->right;
    node->right = subR;
    if (node->bf >= 0) {
        subR->bf = 0;
    } else {
        subR->bf = 1;
    }
    node->bf = 0;
}

template<class K>
void AVLTree<K>::rotateRL(AVLNode<K> *&node) {
    AVLNode<K> *subL = node;
    AVLNode<K> *subR = node->right;
    node = subR->left;
    subR->left = node->right;
    node->right = subR;
    if (node->bf >= 0) {
        subR->bf = 0;
    } else {
        subR->bf = 1;
    }
    subL->right = node->left;
    node->left = subL;
    if (node->bf <= 0) {
        subL->bf = 0;
    } else {
        subL->bf = -1;
    }
    node->bf = 0;
}

template<class K>
int AVLTree<K>::height(AVLNode<K> *node) const {
    if (node == nullptr) {
        return 0;
    }
    queue<AVLNode<K> *> q;
    q.push(node);
    int h = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            AVLNode<K> *top = q.front();
            q.pop();
            if (top->left != nullptr) {
                q.push(top->left);
            }
            if (top->right != nullptr) {
                q.push(top->right);
            }
        }
        h++;
    }
}


