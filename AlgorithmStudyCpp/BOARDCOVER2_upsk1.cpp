#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
vector<vector<pair<int, int>>> rotations;
int Empty = 0;
int blockSize = 0;
vector<string> rotate(const vector<string>& arr) {
    vector<string> ret(arr[0].size(), string(arr.size(), ' '));
    //시계방향으로 90도 회전
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            ret[j][arr.size() - i - 1] = arr[i][j];
        }
    }
    return ret;
}
void generateRotations(vector<string> block) {
    rotations.clear();
    rotations.resize(4);
    for (int rot = 0; rot < 4; rot++) {
        int originX = -1, originY = -1;
        for (int i = 0; i < block.size(); i++) {
            for (int j = 0; j < block[i].size(); j++) {
                if (block[i][j] == '#') {
                    if (originX == -1) {
                        originX = i;
                        originY = j;
                    }
                    rotations[rot].push_back({ i - originX,j - originY });
                }
            }
        }
        block = rotate(block);
    }
    sort(rotations.begin(), rotations.end());
    rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
    //for (int i = 0; i < rotations.size(); i++) {
    //    cout << "블록 " << i << '\n';
    //    for (int j = 0; j < rotations[i].size(); j++) {
    //        cout << rotations[i][j].first << ' ' << rotations[i][j].second << '\n';
    //    }
    //}
    blockSize = rotations[0].size();
}
int boardH, boardW;
vector<string> board;
int covered[10][10];
int best;
bool Set(int x, int y, const vector<pair<int, int>>& block, int delta) {
    if (delta == -1) {
        for (int i = 0; i < block.size(); i++) {
            covered[x + block[i].first][y + block[i].second] = 0;
        }
        return true;
    }
    bool ret = true;
    for (int i = 0; i < block.size(); i++) {
        if (0 <= x + block[i].first && x + block[i].first < boardH && 0 <= y + block[i].second && y + block[i].second < boardW) {
            if (covered[x + block[i].first][y + block[i].second] == 1) {
                ret = false;
                break;
            }
        }
        else {
            ret = false;
            break;
        }
    }
    if (ret) {
        for (int i = 0; i < block.size(); i++) {
            covered[x + block[i].first][y + block[i].second] = 1;
        }
    }
    return ret;
}
void search(int placed) {
    if (Empty / blockSize + placed < best)return;
    /*  cnt++;
      if (cnt > 1000)return;
      cout << placed << '\n';
      for (int i = 0; i < boardH; i++) {
          for (int j = 0; j < boardW; j++) {
              cout << covered[i][j];
          }
          cout << '\n';
      }
      cout << '\n';*/
    int x = -1, y = -1;
    for (int i = 0; i < boardH; i++) {
        for (int j = 0; j < boardW; j++) {
            if (covered[i][j] == 0) {
                x = i;
                y = j;
                break;
            }
        }
        if (x != -1)break;
    }
    if (x == -1) {
        best = max(best, placed);
        return;
    }
    for (int i = 0; i < rotations.size(); i++) {
        if (Set(x, y, rotations[i], 1)) {
            Empty -= blockSize;
            search(placed + 1);
            Set(x, y, rotations[i], -1);
            Empty += blockSize;
        }
    }
    Empty--;
    covered[x][y] = 1;
    search(placed);
    covered[x][y] = 0;
    Empty++;
}
int solve() {
    board.clear();
    best = 0;
    int blockH, blockW;
    cin >> boardH >> boardW >> blockH >> blockW;
    for (int i = 0; i < boardH; i++) {
        string temp;
        cin >> temp;
        board.push_back(temp);
    }
    vector<string> block;
    for (int i = 0; i < blockH; i++) {
        string temp;
        cin >> temp;
        block.push_back(temp);
    }
    generateRotations(block);
    Empty = 0;
    for (int i = 0; i < boardH; i++) {
        for (int j = 0; j < boardW; j++) {
            if (board[i][j] == '#')covered[i][j] = 1;
            else {
                covered[i][j] = 0;
                Empty++;
            }
        }
    }
    search(0);
    return best;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }

}