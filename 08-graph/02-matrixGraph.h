//
// Created by Ignorant on 2024/11/28.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_02_MATRIXGRAPH_H
#define DATA_STRUCTURE_AND_ALGORITHM_02_MATRIXGRAPH_H

#include <iostream>
# include "01-graphBase.h"
using namespace std;


template<class T, class E>
class MatrixGraph : public Graph<T, E> {
    T *vertices;
    E **edges;
public:
    explicit MatrixGraph(int size = defaultVertices);
    ~MatrixGraph();
    
    T getVertexValue(int index) override;
    E getWeight(int from, int to) override;
    int getFirstNeighbor(int vertex) override;
    int getNextNeighbor(int vertex, int start) override;
    int getVertexIndex(T vertex) override;
    
    bool insertVertex(T vertex) override;
    bool insertEdge(int from, int to, E weight) override;
    bool removeVertex(int index) override;
    bool removeEdge(int from, int to) override;
};


#endif //DATA_STRUCTURE_AND_ALGORITHM_02_MATRIXGRAPH_H
