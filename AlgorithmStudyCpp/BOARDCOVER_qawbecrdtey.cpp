#include <iostream>
#include <string>
using namespace std;
int count(string *a, int h, int w, int x, int y) {
    if(y >= w) return count(a, h, w, x + 1, y - w);
    if(x == h - 1) {
        for(int i = 0; i < w; i++) {
            if(a[h - 1][i] == '.') return 0;
        }
        return 1;
    }
    if(a[x][y] != '.') return count(a, h, w, x, y + 1);
    int cnt = 0;
    if(y && a[x + 1][y] == '.' && a[x + 1][y - 1] == '.') {
        a[x][y] = a[x + 1][y] = a[x + 1][y - 1] = '#';
        cnt += count(a, h, w, x, y + 1);
        a[x][y] = a[x + 1][y] = a[x + 1][y - 1] = '.';
    }
    if(y < w - 1 && a[x + 1][y] == '.' && a[x + 1][y + 1] == '.') {
        a[x][y] = a[x + 1][y] = a[x + 1][y + 1] = '#';
        cnt += count(a, h, w, x, y + 1);
        a[x][y] = a[x + 1][y] = a[x + 1][y + 1] = '.';
    }
    if(y < w - 1 && a[x + 1][y] == '.' && a[x][y + 1] == '.') {
        a[x][y] = a[x + 1][y] = a[x][y + 1] = '#';
        cnt += count(a, h, w, x, y + 2);
        a[x][y] = a[x + 1][y] = a[x][y + 1] = '.';
    }
    if(y < w - 1 && a[x][y + 1] == '.' && a[x + 1][y + 1] == '.') {
        a[x][y] = a[x][y + 1] = a[x + 1][y + 1] = '#';
        cnt += count(a, h, w, x, y + 2);
        a[x][y] = a[x][y + 1] = a[x + 1][y + 1] = '.';
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int h, w;
        cin >> h >> w;
        auto a = new string[h];
        for(int i = 0; i < h; i++) cin >> a[i];
        cout << count(a, h, w, 0, 0) << '\n';
        delete[] a;
    }
}