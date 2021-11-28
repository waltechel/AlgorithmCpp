#include <iostream>
#include <string>
using namespace std;
bool dfs(char const plate[5][6], bool visited[5][5][11], string const &s, int x, int y, int cnt) {
    if(visited[x][y][cnt]) return false;
    if(plate[x][y] != s[cnt]) {
        visited[x][y][cnt] = true;
        return false;
    }
    if(cnt == s.size() - 1) return true;
    if(x) {
        if(y && dfs(plate, visited, s, x - 1, y - 1, cnt + 1)) return true;
        if(dfs(plate, visited, s, x - 1, y, cnt + 1)) return true;
        if(y < 4 && dfs(plate, visited, s, x - 1, y + 1, cnt + 1)) return true;
    }
    if(x < 4) {
        if(y && dfs(plate, visited, s, x + 1, y - 1, cnt + 1)) return true;
        if(dfs(plate, visited, s, x + 1, y, cnt + 1)) return true;
        if(y < 4 && dfs(plate, visited, s, x + 1, y + 1, cnt + 1)) return true;
    }
    if(y && dfs(plate, visited, s, x, y - 1, cnt + 1)) return true;
    if(y < 4 && dfs(plate, visited, s, x, y + 1, cnt + 1)) return true;
    visited[x][y][cnt] = true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        char plate[5][6];
        for(auto &i : plate) cin >> i;
        int n; cin >> n;
LOOP:   while(n--) {
            bool visited[5][5][11] = {};
            string s; cin >> s;
            cout << s << ' ';
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    if(dfs(plate, visited, s, i, j, 0)) {
                        cout << "YES\n";
                        goto LOOP;
                    }
                }
            }
            cout << "NO\n";
        }
    }
}