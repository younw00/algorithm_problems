#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int N, M;

int main () {
    cin >> N >> M;
    unordered_map<int, vector<pair<int, int>>> dist; // {u, {v, w}}
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u].push_back({v, w});
        dist[v].push_back({u, w});
    }

    vector<int> min_dist(N+1, INT_MAX);
    min_dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1}); // {거리, 노드}

    while (!pq.empty()) {
        int current_w = pq.top().first;
        int current_u = pq.top().second;
        pq.pop();

        if (current_w > min_dist[current_u]) continue;

        for (int i = 0; i < dist[current_u].size(); i++) {
            int next_v = dist[current_u][i].first;
            int weight = dist[current_u][i].second;
            if (min_dist[next_v] > current_w + weight) {
                min_dist[next_v] = current_w + weight;
                pq.push({min_dist[next_v], next_v});
            }
        }
    }

    cout << min_dist[N] << "\n";

    return 0;
}