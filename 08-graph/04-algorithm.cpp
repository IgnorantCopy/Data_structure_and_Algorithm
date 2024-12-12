//
// Created by Ignorant on 2024/11/28.
//

#include "04-algorithm.h"
#include <queue>
#include "../05-tree/04-minHeap.h"
#include "../06-setDict/01-set/03-UFSet.h"

/********************
 * search algorithm *
 ********************/

template<class T, class E>
void dfs(Graph<T, E>& graph, const T &start) {
    int n = graph.getNumOfVertices();
    auto *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    int index = graph.getVertexIndex(start);
    dfs(graph, index, visited);
    delete[] visited;
}

template<class T, class E>
void dfs(Graph<T, E>& graph, int start, bool *visited) {
    visited[start] = true;
    cout << graph.getVertexValue(start) << " ";
    int next = graph.getFirstNeighbor(start);
    while (next != -1) {
        if (!visited[next]) {
            dfs(graph, next, visited);
        }
        next = graph.getNextNeighbor(start, next);
    }
}

template<class T, class E>
void bfs(Graph<T, E>& graph, const T &start) {
    int n = graph.getNumOfVertices();
    auto *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    queue<int> q;
    int index = graph.getVertexIndex(start);
    q.push(index);
    visited[index] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << graph.getVertexValue(current) << " ";
        int next = graph.getFirstNeighbor(current);
        while (next != -1) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
            next = graph.getNextNeighbor(current, next);
        }
    }
    delete[] visited;
}

template<class T, class E>
int components(Graph<T, E>& graph) {
    int n = graph.getNumOfVertices();
    auto *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited);
            count++;
        }
    }
    delete[] visited;
    return count;
}

/******************************************
 * Minimum Spanning Tree (MST) algorithms *
 ******************************************/

template<class T, class E>
void kruskal(Graph<T, E>& graph, MinSpanningTree<T, E> &mst) {
    MSTEdgeNode<T, E> edge;
    int n = graph.getNumOfVertices();
    int m = graph.getNumOfEdges();
    MinHeap<MSTEdgeNode<T, E>> heap(m);
    UFSet ufSet(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            E weight = graph.getWeight(i, j);
            if (weight != maxValue) {
                edge.tail = i;
                edge.head = j;
                edge.weight = weight;
                heap.insert(edge);
            }
        }
    }
    int count = 1;
    while (count < n) {
        heap.remove(edge);
        int u = ufSet.Find(edge.tail);
        int v = ufSet.Find(edge.head);
        if (u != v) {
            ufSet.Union(u, v);
            mst.insert(edge);
            count++;
        }
    }
}

template<class T, class E>
void prim(Graph<T, E>& graph, MinSpanningTree<T, E> &mst, const T &start) {
    MSTEdgeNode<T, E> edge;
    int n = graph.getNumOfVertices();
    int m = graph.getNumOfEdges();
    int u = graph.getVertexIndex(start);
    MinHeap<MSTEdgeNode<T, E>> heap(m);
    auto *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    visited[u] = true;
    int count = 1;
    do {
        int v = graph.getFirstNeighbor(u);
        while (v != -1) {
            if (!visited[v]) {
                edge.head = v;
                edge.tail = u;
                edge.weight = graph.getWeight(u, v);
                heap.insert(edge);
            }
            v = graph.getNextNeighbor(u, v);
        }
        while (!heap.empty() && count < n) {
            heap.remove(edge);
            if (!visited[edge.head]) {
                mst.insert(edge);
                visited[edge.head] = true;
                u = edge.head;
                count++;
                break;
            }
        }
    } while (count < n);
    delete[] visited;
}

/****************************
 * Shortest Path Algorithms *
 ****************************/

template<class T, class E>
void dijkstra(Graph<T, E>& graph, const T &start, E *dist, int *path) {
    int n = graph.getNumOfVertices();
    auto *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        dist[i] = graph.getWeight(start, i);
        if (i != start && dist[i] != maxValue) {
            path[i] = start;
        } else {
            path[i] = -1;
        }
    }
    visited[start] = true;
    dist[start] = 0;
    for (int i = 0; i < n - 1; i++) {
        float minDist = maxValue;
        int u = start;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                u = j;
                minDist = dist[j];
            }
        }
        visited[u] = true;
        for (int j = 0; j < n; j++) {
            E weight = graph.getWeight(u, j);
            if (!visited[j] && weight != maxValue && dist[u] + weight < dist[j]) {
                dist[j] = dist[u] + weight;
                path[j] = u;
            }
        }
    }
    delete[] visited;
}

template<class T, class E>
void floyd(Graph<T, E>& graph, E **dist, int **path) {
    int n = graph.getNumOfVertices();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph.getWeight(i, j);
            if (i != j && dist[i][j] != maxValue) {
                path[i][j] = i;
            } else {
                path[i][j] = -1;
            }
        }
        for (int k = 0; k < n; k++) {
            for (int ii = 0; ii < n; ii++) {
                for (int j = 0; j < n; j++) {
                    if (dist[ii][j] > dist[ii][k] + dist[k][j]) {
                        dist[ii][j] = dist[ii][k] + dist[k][j];
                        path[ii][j] = path[k][j];
                    }
                }
            }
        }
    }
}

/*******************************
 * Activity Network Algorithms *
 *******************************/

template<class T, class E>
bool topologicalSort(AOV<T, E>& aov) {
    int top = -1;
    int n = aov.getNumOfVertices();
    for (int i = 0; i < n; i++) {
        if (aov.count[i] == 0) {
            aov.count[i] = top;
            top = i;
        }
    }
    int count = 0;
    while (top != -1) {
        top = aov.count[top];
//        aov.removeVertex(top, top);
        int u = aov.getFirstNeighbor(top);
        while (u != -1) {
            aov.count[u]--;
            if (aov.count[u] == 0) {
                aov.count[u] = top;
                top = u;
            }
            u = aov.getNextNeighbor(top, u);
        }
        count++;
    }
    return count == n;
}

template<class T, class E>
void criticalPath(Graph<T, E> &graph) {
    int n = graph.getNumOfVertices();
    auto *vEarly = new E[n];
    auto *vLate = new E[n];
    for (int i = 0; i < n; i++) {
        vEarly[i] = 0;
    }
    vLate[0] = 0;
    for (int i = 0; i < n; i++) {
        int j = graph.getFirstNeighbor(i);
        while (j != -1) {
            E weight = graph.getWeight(i, j);
            vEarly[j] = max(vEarly[j], vEarly[i] + weight);
            j = graph.getNextNeighbor(i, j);
        }
    }
    vLate[n - 1] = vEarly[n - 1];
    for (int j = n - 2; j > 0; j--) {
        int k = graph.getFirstNeighbor(j);
        while (k != -1) {
            E weight = graph.getWeight(j, k);
            vLate[j] = min(vLate[j], vLate[k] - weight);
            k = graph.getNextNeighbor(j, k);
        }
    }
    for (int i = 0; i < n; i++) {
        int j = graph.getFirstNeighbor(i);
        while (j != -1) {
            E aEarly = vEarly[i];
            E aLate = vLate[j] - graph.getWeight(i, j);
            if (aEarly == aLate) {
                cout << '<' << graph.getVertexValue(i) << ',' << graph.getVertexValue(j) << "> is a critical activity.";
            }
            j = graph.getNextNeighbor(i, j);
        }
    }
    delete[] vEarly;
    delete[] vLate;
}
