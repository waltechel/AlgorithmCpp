#include <bits/stdc++.h>
using namespace std;
double a[1001], pre[1001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed;
    cout.precision(11);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        double ans = 200;
        for (int l = k; l <= n; l++) {
            for (int i = 1; i <= n; i++) {
                int start = i, end = i + l - 1;
                if (end > n)break;
                double sum = pre[end] - pre[start - 1];
                ans = min(ans, sum / l);
            }
        }
        cout << ans << '\n';
    }
}