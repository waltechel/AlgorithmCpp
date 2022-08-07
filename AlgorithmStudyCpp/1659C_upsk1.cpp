#include <bits/stdc++.h>
using namespace std;
long long a[200001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        long long n, x, y;
        cin >> n >> x >> y;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans += a[i] * y;
        }
        long long sum = ans;
        for (int i = 1; i <= n; i++) {
            long long dis = a[i] - a[i - 1];
            sum += dis * x;
            sum -= dis * y * (n - i);
            ans = min(ans, sum);
        }
        cout << ans << '\n';

    }

}