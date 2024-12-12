//
// Created by Ignorant on 2024/11/28.
//

#include "02-matrixGraph.h"

template<class T, class E>
int MatrixGraph<T, E>::getVertexIndex(T vertex) {
    for (int i = 0; i < this->numOfVertices; i++) {
        if (this->vertices[i] == vertex) {
            return i;
        }
    }
    return -1;
}

template<class T, class E>
MatrixGraph<T, E>::MatrixGraph(int size): Graph<T, E>(size) {
    this->vertices = new T[this->verticesMax];
    this->edges = new E*[this->verticesMax];
    for (int i = 0; i < this->verticesMax; i++) {
        this->edges[i] = new E[this->verticesMax];
        for (int j = 0; j < this->verticesMax; j++) {
            if (i == j) {
                this->edges[i][j] = E(0);
            } else {
                this->edges[i][j] = E(maxWeight);
            }
        }
    }
}

template<class T, class E>
MatrixGraph<T, E>::~MatrixGraph() {
    delete[] this->vertices;
    delete[] this->edges;
}

template<class T, class E>
T MatrixGraph<T, E>::getVertexValue(int index) {
    if (index < 0 || index >= this->numOfVertices) {
        return T();
    }
    return this->vertices[index];
}

template<class T, class E>
E MatrixGraph<T, E>::getWeight(int from, int to) {
    if (from == -1 || to == -1) {
        return E(0);
    }
    return this->edges[from][to];
}

template<class T, class E>
int MatrixGraph<T, E>::getFirstNeighbor(int vertex) {
    if (vertex == -1) {
        return -1;
    }
    for (int i = 0; i < this->numOfVertices; i++) {
        if (this->edges[vertex][i] != E(0) && this->edges[vertex][i] != E(maxWeight)) {
            return i;
        }
    }
    return -1;
}

template<class T, class E>
int MatrixGraph<T, E>::getNextNeighbor(int vertex, int start) {
    if (vertex == -1 || start == -1) {
        return -1;
    }
    for (int i = start + 1; i < this->numOfVertices; i++) {
        if (this->edges[vertex][i] != E(0) && this->edges[vertex][i] != E(maxWeight)) {
            return i;
        }
    }
    return -1;
}

template<class T, class E>
bool MatrixGraph<T, E>::insertVertex(T vertex) {
    if (this->numOfVertices >= this->verticesMax) {
        return false;
    }
    this->vertices[this->numOfVertices++] = vertex;
    return true;
}

template<class T, class E>
bool MatrixGraph<T, E>::insertEdge(int from, int to, E weight) {
    if (from == -1 || to == -1 || from >= this->numOfVertices || to >= this->numOfVertices) {
        return false;
    }
    this->edges[from][to] = weight;
    return true;
}

template<class T, class E>
bool MatrixGraph<T, E>::removeVertex(int index) {
    if (index == -1 || index >= this->numOfVertices) {
        return false;
    }
    vertices[index] = T();
    this->numOfVertices--;
    for (int i = 0; i < this->verticesMax; i++) {
        this->edges[index][i] = E(maxWeight);
        this->edges[i][index] = E(maxWeight);
    }
    this->edges[index][index] = E(0);
    return true;
}

template<class T, class E>
bool MatrixGraph<T, E>::removeEdge(int from, int to) {
    if (from == -1 || to == -1 || from >= this->numOfVertices || to >= this->numOfVertices) {
        return false;
    }
    this->edges[from][to] = E(maxWeight);
}
