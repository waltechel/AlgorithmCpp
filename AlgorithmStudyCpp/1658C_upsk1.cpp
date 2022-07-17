#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int cnt1 = 0, idx;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                cnt1++;
                idx = i;
            }
        }
        if (cnt1 != 1) {
            cout << "NO\n";
            continue;
        }
        bool flag = true;
        for (int i = idx + 1; i < idx + n; i++) {
            int i2 = i % n;
            int prev = i2 - 1;
            if (prev < 0)prev = n - 1;
            if (a[i2] - a[prev] > 1) {
                flag = false;
                break;
            }
        }
        if (flag)cout << "YES\n";
        else cout << "NO\n";
    }


}