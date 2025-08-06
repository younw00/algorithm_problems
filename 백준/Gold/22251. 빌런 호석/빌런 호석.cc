#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

// 7-segment bit patterns for 0~9
string segment[10] = {
    "1111110", "0110000", "1101101", "1111001", "0110011",
    "1011011", "1011111", "1110000", "1111111", "1111011"
};

// 두 숫자 간 LED 반전 개수 계산
int calc_diff(int a, int b) {
    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        if (segment[a][i] != segment[b][i]) cnt++;
    }
    return cnt;
}

// K자리 수로 변환
vector<int> get_digits(int num, int K) {
    vector<int> res(K, 0);
    for (int i = K - 1; i >= 0; i--) {
        res[i] = num % 10;
        num /= 10;
    }
    return res;
}

int main() {
    int N, K, P, X;
    cin >> N >> K >> P >> X;

    // 현재 층 숫자 K자리
    vector<int> x_digits = get_digits(X, K);

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        if (i == X) continue;

        vector<int> candidate = get_digits(i, K);

        int diff = 0;
        for (int d = 0; d < K; d++) {
            diff += calc_diff(x_digits[d], candidate[d]);
        }

        if (1 <= diff && diff <= P) {
            answer++;
        }
    }

    cout << answer << '\n';
    return 0;
}
