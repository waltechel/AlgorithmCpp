#include <bits/stdc++.h>
using namespace std;
int a[16];
vector<int> v[10];
int ans;
void solve(int idx, int sum) {
    if (idx == 10) {
        for (int i = 0; i < 16; i++) {
            if (a[i] != 12)return;
        }
        ans = sum;
        return;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < v[idx].size(); j++) {
            a[v[idx][j]] += 3;
            if (a[v[idx][j]] > 12)a[v[idx][j]] = 3;
        }
        solve(idx + 1, sum + (i + 1) % 4);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    v[0].push_back(0); v[0].push_back(1); v[0].push_back(2);
    v[1].push_back(3); v[1].push_back(7); v[1].push_back(9); v[1].push_back(11);
    v[2].push_back(4); v[2].push_back(10); v[2].push_back(14); v[2].push_back(15);
    v[3].push_back(0); v[3].push_back(4); v[3].push_back(5); v[3].push_back(6); v[3].push_back(7);
    v[4].push_back(6); v[4].push_back(7); v[4].push_back(8); v[4].push_back(10); v[4].push_back(12);
    v[5].push_back(0); v[5].push_back(2); v[5].push_back(14); v[5].push_back(15);
    v[6].push_back(3); v[6].push_back(14); v[6].push_back(15);
    v[7].push_back(4); v[7].push_back(5); v[7].push_back(7); v[7].push_back(14); v[7].push_back(15);
    v[8].push_back(1); v[8].push_back(2); v[8].push_back(3); v[8].push_back(4); v[8].push_back(5);
    v[9].push_back(3); v[9].push_back(4); v[9].push_back(5); v[9].push_back(9); v[9].push_back(13);
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 16; i++)cin >> a[i];
        ans = 10000;
        solve(0, 0);
        if (ans == 10000) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}