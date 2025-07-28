#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

using namespace std;

int main () {
    int N;
    cin >> N;

    vector<int> liquids(N);
    for (int i = 0; i < N; i++) {
        cin >> liquids[i];
    }

    int start = 0, end = N - 1;
    int best = INT_MAX;
    pair<int,int> answer;

    while (start < end) {
        int sum = liquids[start] + liquids[end];

        if (abs(sum) < best) {
            best = abs(sum);
            answer.first = liquids[start];
            answer.second = liquids[end];
        }

        if (sum < 0) start++;
        else if (sum > 0) end--;
        else break;
    }

    cout << answer.first << " " << answer.second << "\n";
    return 0;
}
