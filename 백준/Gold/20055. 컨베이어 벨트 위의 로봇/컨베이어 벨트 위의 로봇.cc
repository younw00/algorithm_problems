#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    deque<int> belt(2 * N);         // 내구도
    deque<bool> robots(2 * N, false); // 로봇 위치

    for (int i = 0; i < 2 * N; i++) {
        cin >> belt[i];
    }

    int step = 0;
    int zero_count = 0;

    while (true) {
        step++;

        // 1. 벨트와 로봇 함께 회전
        belt.push_front(belt.back());
        belt.pop_back();

        robots.push_front(robots.back());
        robots.pop_back();
        robots[N - 1] = false; // 내리는 위치는 무조건 비워짐

        // 2. 로봇 이동
        for (int i = N - 2; i >= 0; i--) {
            if (robots[i] && !robots[i + 1] && belt[i + 1] > 0) {
                robots[i] = false;
                robots[i + 1] = true;
                belt[i + 1]--;
                if (belt[i + 1] == 0) zero_count++;
            }
        }
        robots[N - 1] = false; // 내리는 위치 도달 시 즉시 내림

        // 3. 로봇 올리기
        if (!robots[0] && belt[0] > 0) {
            robots[0] = true;
            belt[0]--;
            if (belt[0] == 0) zero_count++;
        }

        // 4. 종료 조건 확인
        if (zero_count >= K) break;
    }

    cout << step << '\n';
    return 0;
}
