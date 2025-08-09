#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C;
    cin >> N >> C;
    vector<long long> x(N);
    for (int i = 0; i < N; ++i) cin >> x[i];
    sort(x.begin(), x.end());

    auto can = [&](long long d) -> bool {
        int cnt = 1;                  // 첫 집에 설치
        long long last = x[0];
        for (int i = 1; i < N; ++i) {
            if (x[i] - last >= d) {   // d 이상 간격이면 설치
                cnt++;
                last = x[i];
                if (cnt >= C) return true;
            }
        }
        return false;
    };

    long long lo = 1, hi = x.back() - x.front(), ans = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (can(mid)) {          // mid 간격으로 C개 설치 가능 → 더 키워본다
            ans = mid;
            lo = mid + 1;
        } else {                 // 불가능 → 줄인다
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
