#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int N, M;
unordered_map<int, int> warp; // 사다리/뱀 통합

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        warp[x] = y;
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        warp[u] = v;
    }

    vector<bool> visited(101, false);
    queue<pair<int, int>> q; // {위치, 주사위 횟수}
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty()) {
        int pos = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (pos == 100) {
            cout << depth << '\n';
            return 0;
        }

        for (int dice = 1; dice <= 6; dice++) {
            int next = pos + dice;
            if (next > 100) continue;

            // 사다리나 뱀 타기
            if (warp.count(next)) {
                next = warp[next];
            }

            if (!visited[next]) {
                visited[next] = true;
                q.push({next, depth + 1});
            }
        }
    }

    return 0;
}
