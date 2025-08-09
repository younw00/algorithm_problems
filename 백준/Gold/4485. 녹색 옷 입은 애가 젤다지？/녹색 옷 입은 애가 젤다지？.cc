#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N;
vector<vector<int>> map;

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

int main () {
    int tc = 1;
    cin >> N;
    while (N != 0) {
        map = vector<vector<int>> (N, vector<int> (N));

        for (int i = 0; i < N; i++) {
            for (int  j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }

        vector<vector<int>> min_cost (N, vector<int> (N, INT_MAX));
        min_cost[0][0] = map[0][0];

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({map[0][0], 0, 0}); // cost, i, j
        
        while (!pq.empty()) {
            int current_cost = pq.top()[0];
            int current_i = pq.top()[1];
            int current_j = pq.top()[2];
            pq.pop();

            if (current_cost > min_cost[current_i][current_j]) continue;

            for (int d = 0; d < 4; d++) {
                int ni = current_i + di[d];
                int nj = current_j + dj[d];
                if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                    int ncost = current_cost + map[ni][nj];
                    if (ncost < min_cost[ni][nj]) {
                        min_cost[ni][nj] = ncost;
                        pq.push({ncost, ni, nj});
                    }
                }
            }
        }
        
        cout << "Problem " << tc << ": " << min_cost[N-1][N-1] << "\n";
        cin >> N;
        tc += 1;
    }
    return 0;
}