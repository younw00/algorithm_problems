#include <bits/stdc++.h>
using namespace std;

int N, L, R;
vector<vector<int>> A;          // 인구
vector<vector<int>> visited;    // 방문 체크 (하루 단위로 초기화)

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

bool inRange(int x, int y) { return 0 <= x && x < N && 0 <= y && y < N; }

// (i, j)에서 시작해 연합을 DFS로 모은다
void dfs(int i, int j, vector<pair<int,int>>& comp, int& sum) {
    visited[i][j] = 1;
    comp.push_back({i, j});
    sum += A[i][j];

    for (int d = 0; d < 4; d++) {
        int ni = i + di[d];
        int nj = j + dj[d];
        if (!inRange(ni, nj) || visited[ni][nj]) continue;

        int diff = abs(A[i][j] - A[ni][nj]);
        if (L <= diff && diff <= R) {
            dfs(ni, nj, comp, sum);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L >> R;
    A.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    int days = 0;

    while (true) {
        visited.assign(N, vector<int>(N, 0));
        bool moved = false; // 이날 한 번이라도 인구가 바뀌었는가?

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j]) continue;

                vector<pair<int,int>> comp;
                int sum = 0;
                dfs(i, j, comp, sum);

                // 연합 크기가 2 이상일 때만 평균으로 갱신
                if ((int)comp.size() > 1) {
                    int avg = sum / (int)comp.size();
                    for (auto& p : comp) {
                        if (A[p.first][p.second] != avg) {
                            A[p.first][p.second] = avg;
                            moved = true;
                        }
                    }
                }
            }
        }

        if (!moved) break; // 더 이상 이동이 없으면 종료
        days++;
    }

    cout << days << '\n';
    return 0;
}
