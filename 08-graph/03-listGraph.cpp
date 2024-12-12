//
// Created by Ignorant on 2024/11/28.
//

#include "03-listGraph.h"

template<class T, class E>
int ListGraph<T, E>::getVertexIndex(T vertex) {
    for (int i = 0; i < this->numOfVertices; i++) {
        if (this->vertices[i] == vertex) {
            return i;
        }
    }
    return -1;
}

template<class T, class E>
T ListGraph<T, E>::getVertexValue(int index) {
    if (index < 0 || index >= this->numOfVertices) {
        return T();
    }
    return this->vertices[index].data;
}

template<class T, class E>
ListGraph<T, E>::ListGraph(int size): Graph<T, E>(size) {
    this->vertices = new Vertex<T, E>[this->verticesMax];
}

template<class T, class E>
ListGraph<T, E>::~ListGraph() {
    for (int i = 0; i < this->numOfVertices; i++) {
        Edge<T, E> *edge = this->vertices[i].head;
        while (edge != nullptr) {
            Edge<T, E> *temp = edge;
            edge = edge->next;
            delete temp;
        }
    }
    delete[] this->vertices;
}

template<class T, class E>
int ListGraph<T, E>::getFirstNeighbor(int index) {
    if (index == -1) {
        return -1;
    }
    Edge<T, E> *temp = this->vertices[index].head;
    if (temp == nullptr) {
        return -1;
    }
    return temp->to;
}

template<class T, class E>
int ListGraph<T, E>::getNextNeighbor(int index, int start) {
    if (index == -1) {
        return -1;
    }
    Edge<T, E> *temp = this->vertices[index].head;
    while (temp != nullptr && temp->to != start) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        return -1;
    }
    return temp->next->to;
}

template<class T, class E>
E ListGraph<T, E>::getWeight(int from, int to) {
    if (from == -1 || to == -1 || from >= this->numOfVertices || to >= this->numOfVertices) {
        return E();
    }
    Edge<T, E> *temp = this->vertices[from].head;
    while (temp != nullptr && temp->to != to) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        return E();
    }
    return temp->weight;
}

template<class T, class E>
bool ListGraph<T, E>::insertVertex(T vertex) {
    if (this->numOfVertices >= this->verticesMax) {
        return false;
    }
    this->vertices[this->numOfVertices].data = vertex;
    this->vertices[this->numOfVertices].head = nullptr;
    this->numOfVertices++;
    return true;
}

template<class T, class E>
bool ListGraph<T, E>::insertEdge(int from, int to, E weight) {
    if (from == -1 || to == -1 || from >= this->numOfVertices || to >= this->numOfVertices) {
        return false;
    }
    auto *edge = new Edge<T, E>(to, weight);
    if (Edge<T, E> *temp = this->vertices[from].head; temp == nullptr) {
        this->vertices[from].head = edge;
    } else {
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = edge;
    }
    return true;
}

template<class T, class E>
bool ListGraph<T, E>::removeVertex(int index) {
    if (index == -1 || index >= this->numOfVertices) {
        return false;
    }
    for (int i = 0; i < this->numOfVertices; i++) {
        Edge<T, E> *edge = this->vertices[i].head;
        if (i == index) {
            while (edge != nullptr) {
                Edge<T, E> *temp = edge;
                edge = edge->next;
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
    this->numOfVertices--;
    return true;
}

template<class T, class E>
bool ListGraph<T, E>::removeEdge(int from, int to) {
    if (from == -1 || to == -1 || from >= this->numOfVertices || to >= this->numOfVertices) {
        return false;
    }
    Edge<T, E> *edge = this->vertices[from].head;
    if (edge == nullptr) {
        return false;
    }
    if (edge->to == to) {
        this->vertices[from].head = edge->next;
        delete edge;
        return true;
    }
    while (edge->next != nullptr) {
        if (edge->next->to == to) {
            Edge<T, E> *temp = edge->next;
            edge->next = edge->next->next;
            delete temp;
            return true;
        }
        edge = edge->next;
    }
    return false;
}
