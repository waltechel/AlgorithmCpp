#include <bits/stdc++.h>
using namespace std;
long long a[100001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)cin >> a[i];
        sort(a, a + n);
        if (a[n - 1] == 0) {
            cout << 0 << '\n';
            continue;
        }
        long long sum = 0;
        long long ans = 1;
        for (int i = 0; i < n - 1; i++)sum += a[i];
        if (sum + 1 < a[n - 1]) {
            ans += (a[n - 1] - (sum + 1LL));
        }
        cout << ans << '\n';
    }
}