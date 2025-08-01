#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int N, E, v1, v2;

vector<vector<pair<int,int>>> graph;
vector<int> dijkstra_from_1;
vector<int> dijkstra_from_v1;
vector<int> dijkstra_from_v2;

vector<int> dijkstra (int start) {
    vector<int> dist(N+1, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, start}); // {distance, node}

    while (!pq.empty()) {
        auto [current_distance, u] = pq.top();
        pq.pop();

        if (dist[u] < current_distance) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[v] > current_distance + w) {
                dist[v] = current_distance + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main () {
    cin >> N >> E;
    graph.resize(N+1);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    cin >> v1 >> v2;
    dijkstra_from_1 = dijkstra(1); // 1 -> 모든 정점
    dijkstra_from_v1 = dijkstra(v1); // v1 -> 모든 정점
    dijkstra_from_v2 = dijkstra(v2); // v2 -> 모든 정점
    
    int path1 = dijkstra_from_1[v1] + dijkstra_from_v1[v2] + dijkstra_from_v2[N];
    int path2 = dijkstra_from_1[v2] + dijkstra_from_v2[v1] + dijkstra_from_v1[N];
    int answer = min(path1, path2);
    // INT_MAX가 하나라도 있으면 경로 불가능
    if (dijkstra_from_1[v1] == INT_MAX || dijkstra_from_1[v2] == INT_MAX ||
        dijkstra_from_v1[v2] == INT_MAX || dijkstra_from_v1[N] == INT_MAX ||
        dijkstra_from_v2[v1] == INT_MAX || dijkstra_from_v2[N] == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << answer << '\n';
    }

}