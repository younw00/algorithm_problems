#include <iostream>
#include <unordered_map>
#include <climits>
#include <vector>

using namespace std;

int T, K;
string W;

int main () {
    cin >> T;
    for (int test = 0; test < T; test++) {
        cin >> W >> K;
        
        int min_length = INT_MAX;
        int max_length = INT_MIN;
        unordered_map<char, vector<int>> index;

        for (int i = 0; i < W.length(); i++) {
            index[W[i]].push_back(i);
        }

        for (auto& ch_index : index) {
            if (ch_index.second.size() < K) continue;
            for (int i = 0; i < ch_index.second.size() - K + 1; i++) {
                int start = ch_index.second[i];
                int end = ch_index.second[i + K - 1];
                if (min_length > end - start + 1) {
                    min_length = end - start + 1;
                }

                if (max_length < end - start + 1) {
                    max_length = end - start + 1;
                }
            }
        }

        if (min_length == INT_MAX || max_length == INT_MIN) cout << -1 << "\n";
        else cout << min_length << " " << max_length << "\n";
        
    }
    return 0;
}