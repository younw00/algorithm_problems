#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;

int main () {
    cin >> N >> K;

    vector<bool> visited (100001, false);
    queue<pair<int,int>> q;
    q.push({N, 0});
    visited[N] = true;

    while (!q.empty()) {
        int current = q.front().first;
        int time = q.front().second;
        q.pop();
        visited[current] = true;

        if (current == K) {
            cout << time << "\n";
            break;
        }

        if (2*current <= 100000 && !visited[2*current]) {
            q.push({2*current, time});  // 순간이동은 0초
            visited[2*current] = true;
        }
        if (current-1 >= 0 && !visited[current-1]) {
            q.push({current-1, time+1});
            visited[current-1] = true;
        }
        if (current+1 <= 100000 && !visited[current+1]) {
            q.push({current+1, time+1});
            visited[current+1] = true;
        }
    }
}