//
// Created by Ignorant on 2024/11/28.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_03_LISTGRAPH_H
#define DATA_STRUCTURE_AND_ALGORITHM_03_LISTGRAPH_H

#include <iostream>
#include "01-graphBase.h"
using namespace std;

template<class T, class E>
struct Edge {
    int to = -1;
    E weight = 0;
    Edge<T, E> *next = nullptr;
    
    Edge() = default;
    Edge(int to, E weight): to(to), weight(weight) {}
    
    bool operator!=(const Edge<T, E>& other) { return to != other.to; }
};

template<class T, class E>
struct Vertex {
    T data;
    Edge<T, E> *head = nullptr;
    
    Vertex() = default;
    
    explicit Vertex(T data): data(data) {}
};

template<class T, class E>
class ListGraph: public Graph<T, E> {
    Vertex<T, E> *vertices = nullptr;
public:
    explicit ListGraph(int size = defaultVertices);
    ~ListGraph();
    
    T getVertexValue(int index) override;
    E getWeight(int from, int to) override;
    bool insertVertex(T vertex) override;
    bool insertEdge(int from, int to, E weight) override;
    bool removeVertex(int index) override;
    bool removeEdge(int from, int to) override;
    
    int getFirstNeighbor(int index) override;
    int getNextNeighbor(int index, int start) override;
    int getVertexIndex(T vertex) override;
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_03_LISTGRAPH_H
