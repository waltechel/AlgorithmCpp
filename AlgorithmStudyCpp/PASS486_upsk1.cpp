#include <bits/stdc++.h>
using namespace std;
int d[10000001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i < 10000001; i++) {
        for (int j = i; j < 10000001; j += i) {
            d[j]++;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;
        int ans = 0;
        for (int i = l; i <= r; i++) {
            if (d[i] == n)ans++;
        }
        cout << ans << '\n';
    }
}