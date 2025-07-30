#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N;
vector<int> nums;
set<int> answer;  // 중복 제거 자동
vector<bool> visited;
vector<bool> in_path;

void dfs(int current, vector<int> path) {
    visited[current] = true;
    in_path[current] = true;
    path.push_back(current);

    int next = nums[current];
    if (!visited[next]) {
        dfs(next, path);
    }
    else if (in_path[next]) {
        auto it = find(path.begin(), path.end(), next);
        for (; it != path.end(); it++) {
            answer.insert(*it);  // 중복 없이 저장
        }
    }

    in_path[current] = false;
}

int main() {
    cin >> N;
    nums.resize(N + 1);
    visited.resize(N + 1, false);
    in_path.resize(N + 1, false);

    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            vector<int> path;
            dfs(i, path);
        }
    }

    cout << answer.size() << " ";
    for (int num : answer) {
        cout << num << " ";
    }

    return 0;
}
