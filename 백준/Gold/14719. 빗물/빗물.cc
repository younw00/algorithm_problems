#include <iostream>
#include <vector>

using namespace std;

int H, W;

int main () {
    cin >> H >> W;
    vector<int> blocks;
    for (int i = 0; i < W; i++) {
        int h;
        cin >> h;
        blocks.push_back(h);
    }

    vector<int> left_max(W, 0);
    vector<int> right_max(W, 0);

    int current_max = blocks[0];
    for (int i = 0; i < W; i++) {
        current_max = max(current_max, blocks[i]);
        left_max[i] = current_max;
    }

    current_max = blocks[W-1];
    for (int i = W-1; i >= 0; i--) {
        current_max = max(current_max, blocks[i]);
        right_max[i] = current_max;
    }

    int answer = 0;
    for (int i = 0; i < W; i++) {
        answer += min(left_max[i], right_max[i]) - blocks[i];
    }

    cout << answer << "\n";
    return 0;
}