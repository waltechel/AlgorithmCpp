#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000100;
int d[201][201];
int total;
void solve(int n, int m, string s) {
    if (total < 0)return;
    if (n == 0 && m == 0) {
        if (total == 0)cout << s << '\n';
        total--;
        return;
    }
    if (d[n + m][n] <= total) {
        total -= d[n + m][n];
        return;
    }
    if (n > 0)solve(n - 1, m, s + '-');
    if (m > 0)solve(n, m - 1, s + 'o');
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    d[1][1] = 1; d[1][0] = 1; d[2][0] = 1; d[2][1] = 2; d[2][2] = 1;
    for (int i = 3; i < 201; i++) {
        d[i][0] = 1; d[i][1] = i;
        for (int j = 2; j <= i; j++) {
            d[i][j] = min(MAX, d[i - 1][j - 1] + d[i - 1][j]);
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        total = k - 1;
        solve(n, m, "");
    }
}