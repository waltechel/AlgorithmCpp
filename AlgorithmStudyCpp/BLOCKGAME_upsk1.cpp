#include <bits/stdc++.h>
using namespace std;
string s[5];
vector<int> blocks;
int cell(int x, int y) {
    return 1 << (x * 5 + y);
}
void precalc() {
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            vector<int> cells;
            for (int dx = 0; dx < 2; dx++) {
                for (int dy = 0; dy < 2; dy++) {
                    cells.push_back(cell(x + dx, y + dy));
                }
            }
            int square = 0;
            for (int i = 0; i < 4; i++)square += cells[i];
            for (int i = 0; i < 4; i++)blocks.push_back(square - cells[i]);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            blocks.push_back(cell(i, j) + cell(i, j + 1));
            blocks.push_back(cell(j, i) + cell(j + 1, i));
        }
    }
}
char d[1 << 25];
char solve(int state) {
    if (d[state] != -1)return d[state];
    d[state] = 0;
    for (int i = 0; i < blocks.size(); i++) {
        //만약 내가 놓을 수 있고
        if ((blocks[i] & state) == 0) {
            //상대방이 놓지 못한다면
            if (!solve((state | blocks[i]))) {
                d[state] = 1;
                break;
            }
        }
    }
    return d[state];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    precalc();
    int T;
    cin >> T;
    while (T--) {
        memset(d, -1, sizeof(d));
        int state = 0;
        for (int i = 0; i < 5; i++) {
            cin >> s[i];
            for (int j = 0; j < 5; j++) {
                if (s[i][j] == '#')state |= cell(i, j);
            }
        }
        if (solve(state))cout << "WINNING\n";
        else cout << "LOSING\n";
    }
}