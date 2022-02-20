#include <bits/stdc++.h>
using namespace std;
const int inf = -60000;

int a[51];
int d[51][51];
int solve(int l, int r) {
    if (l > r)return 0;
    if (d[l][r] != inf)return d[l][r];
    d[l][r] = max(a[l] - solve(l + 1, r), a[r] - solve(l, r - 1));
    if (r - l >= 1) {
        d[l][r] = max({ d[l][r],-solve(l + 2,r),-solve(l,r - 2) });
    }
    return d[l][r];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)cin >> a[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = inf;
            }
        }
        cout << solve(0, n - 1) << '\n';
    }
}