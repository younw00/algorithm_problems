#include <iostream>
#include <vector>

using namespace std;

bool isWin (char player, string board) {
    if (board[0] == player && board[1] == player && board[2] == player) return true;
    if (board[3] == player && board[4] == player && board[5] == player) return true;
    if (board[6] == player && board[7] == player && board[8] == player) return true;
    if (board[0] == player && board[3] == player && board[6] == player) return true;
    if (board[1] == player && board[4] == player && board[7] == player) return true;
    if (board[2] == player && board[5] == player && board[8] == player) return true;
    if (board[0] == player && board[4] == player && board[8] == player) return true;
    if (board[2] == player && board[4] == player && board[6] == player) return true;
    return false;
}

int main () {
    string board;
    cin >> board;
    while (board != "end") {
        bool valid = true; // 가능하다고 가상설정
        int x_num = 0;
        int o_num = 0;
        for (char ch : board) {
            if (ch == 'O') o_num += 1;
            else if (ch == 'X') x_num += 1;
        }

        bool x_win = isWin('X', board);
        bool o_win = isWin('O', board);

        if (o_num > x_num || x_num - o_num > 1) valid = false;
        else if (x_win && o_win) valid = false;
        else if (x_win && x_num != o_num + 1) valid = false;
        else if (o_win && o_num != x_num) valid = false;
        else if (!o_win && !x_win && x_num + o_num != 9) valid = false;

        cout << (valid ? "valid" : "invalid") << '\n';

        cin >> board;
    }
    return 0;
}