//
// Created by Ignorant on 2024/11/15.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define INF 1e9
using namespace std;

void dijkstra(int s,int n, vector<map<int, int>> edges) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // (distance, index)
    auto *dist = new int[n];
    auto *visited = new int[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = 1;
        for (auto [v, w] : edges[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            cout << "NA ";
        } else {
            cout << dist[i] << " ";
        }
    }
    delete[] dist;
    delete[] visited;
}

int main() {
    int n = 0;
    int m = 0;
    int s = 0;
    cin >> n >> m >> s;
    vector<map<int, int>> edges(n);
    for (int i = 0; i < n; i++) {
        edges[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u = 0;
        int v = 0;
        int w = 0;
        cin >> u >> v >> w;
        if (edges[u - 1].find(v - 1) != edges[u - 1].end()) {
            edges[u - 1][v - 1] = min(edges[u - 1][v - 1], w);
        } else {
            edges[u - 1][v - 1] = w;
        }
    }
    dijkstra(s - 1, n, edges);
    return 0;
}
