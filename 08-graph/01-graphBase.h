//
// Created by Ignorant on 2024/11/28.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_01_GRAPHBASE_H
#define DATA_STRUCTURE_AND_ALGORITHM_01_GRAPHBASE_H

#include <iostream>
using namespace std;

const int maxWeight = INT_MAX;
const int defaultVertices = 30;

// 无向带权图
template<class T, class E>      // T: 顶点类型，E: 边权类型
class Graph {
protected:
    int verticesMax = defaultVertices;
    int numOfEdges = 0;
    int numOfVertices = 0;
public:
    explicit Graph(int size = defaultVertices): verticesMax(size) {}
    ~Graph() = default;
    
    [[nodiscard]] bool isEmpty() const { return numOfVertices == 0; }
    [[nodiscard]] int getNumOfVertices() const { return numOfVertices; }
    [[nodiscard]] int getNumOfEdges() const { return numOfEdges; }
    
    virtual T getVertexValue(int index);
    virtual E getWeight(int from, int to);
    virtual int getFirstNeighbor(int vertex);
    virtual int getNextNeighbor(int vertex, int start);
    virtual int getVertexIndex(T vertex);
    
    virtual bool insertVertex(const T vertex);
    virtual bool insertEdge(int from, int to, const E weight);
    virtual bool removeVertex(int index);
    virtual bool removeEdge(int from, int to);
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_01_GRAPHBASE_H
