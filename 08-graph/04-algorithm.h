//
// Created by Ignorant on 2024/11/28.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_04_ALGORITHM_H
#define DATA_STRUCTURE_AND_ALGORITHM_04_ALGORITHM_H

#include <iostream>
#include "01-graphBase.h"
#include "03-listGraph.h"
using namespace std;


const float maxValue = 1e9;
int defaultSize = 100;

template<class T, class E>
struct MSTEdgeNode {
    int tail = -1;
    int head = -1;
    E weight = 0;
    
    MSTEdgeNode() = default;
    MSTEdgeNode(int t, int h, E w) : tail(t), head(h), weight(w) {}
    bool operator<(const MSTEdgeNode<T, E> &other) const {
        return weight < other.weight;
    }
};

template<class T, class E>
class MinSpanningTree {
protected:
    MSTEdgeNode<T, E> *edges;
    int capacity = defaultSize;
    int size = 0;
public:
    explicit MinSpanningTree(int size = defaultSize): capacity(size) {
        edges = new MSTEdgeNode<T, E>[capacity];
    }
    ~MinSpanningTree() {
        delete[] edges;
    }
    int insert(MSTEdgeNode<T, E> &node) {
        if (size == capacity) {
            capacity *= 2;
            auto *newEdges = new MSTEdgeNode<T, E>[capacity];
            for (int i = 0; i < size; i++) {
                newEdges[i] = edges[i];
            }
            delete[] edges;
            edges = newEdges;
        }
        edges[size++] = node;
        return size - 1;
    }
};

template<class T, class E>
class AOV: public ListGraph<T, E> {
public:
    int *count = nullptr;
    
    AOV(int size = defaultSize): ListGraph<T, E>(size) {
        count = new int[size];
        for (int i = 0; i < size; i++) {
            count[i] = 0;
        }
    }
    ~AOV() { delete[] count; }

    bool insertEdge(int from, int to, E weight) override {
        bool result = ListGraph<T, E>::insertEdge(from, to, weight);
        if (result) {
            count[to]++;
        }
        return result;
    }
    
    bool removeEdge(int from, int to, int &top)  {
        bool result = ListGraph<T, E>::removeEdge(from, to);
        if (result) {
            count[to]--;
            if (count[to] == 0) {
                count[to] = top;
                top = to;
            }
        }
        return result;
    }
    
    bool removeVertex(int index, int &top) {
        if (index == -1 || index >= this->numOfVertices) {
            return false;
        }
        for (int i = 0; i < this->numOfVertices; i++) {
            Edge<T, E> *edge = this->vertices[i].head;
            if (i == index) {
                while (edge != nullptr) {
                    Edge<T, E> *temp = edge;
                    edge = edge->next;
                    count[temp->to]--;
                    if (count[temp->to] == 0) {
                        count[temp->to] = top;
                        top = temp->to;
                    }
                    delete temp;
                }
                this->vertices[index].data = T();
                this->vertices[index].head = nullptr;
            } else {
                while (edge->next != nullptr) {
                    if (edge->next->to == index) {
                        Edge<T, E> *temp = edge->next;
                        edge->next = edge->next->next;
                        delete temp;
                        break;
                    } else {
                        edge = edge->next;
                    }
                }
            }
        }
        this->count[index] = 0;
        this->numOfVertices--;
        return true;
    }
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_04_ALGORITHM_H
