#include <bits/stdc++.h>
using namespace std;
long long a[400001];
int cnt[100], ocnt[100];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 20; i++) {
            cnt[i] = 0;
            ocnt[i] = 0;
        }
        long long l, r;
        cin >> l >> r;
        for (int i = l; i <= r; i++) {
            for (int j = 0; j < 20; j++) {
                if ((i & (1 << j))) {
                    ocnt[j]++;
                }
            }
        }
        long long dif = r - l + 1;
        long long ans = 0;
        for (int i = 0; i < dif; i++) {
            cin >> a[i];
            for (int j = 0; j < 20; j++) {
                if ((a[i] & (1 << j))) {
                    cnt[j]++;
                }
            }
        }
        for (int i = 0; i < 20; i++) {
            if (ocnt[i] != cnt[i]) {
                ans += (1 << i);
            }
        }
        cout << ans << '\n';
    }


}