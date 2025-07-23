#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main () {
    string S, T;
    cin >> S >> T;
    queue<string> q;

    q.push(T);
    bool found = false;

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (current == S) {
            found = true;
            break;
        }
        if (current.length() < S.length()) break;
;
        if (current.back() == 'A') {
            string temp = current.substr(0, current.size()-1);
            q.push(temp);
        }

        reverse(current.begin(), current.end());
        if (current.back() == 'B') {
            string temp = current.substr(0, current.size()-1);
            q.push(temp);
        }
    }

    if (found) cout << 1 << "\n";
    else cout << 0 << "\n";
    
    return 0;
}