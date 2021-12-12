#include <bits/stdc++.h>
using namespace std;
long long dp[101][11];
long long psum[101], psum2[101], a[101], n, s;
const long long inf = 1000000000;
int minError(int l, int r) {
    int sum = psum[r] - psum[l - 1], sum2 = psum2[r] - psum2[l - 1];
    int mid = int(0.5 + (double)sum / (r - l + 1));
    return sum2 - 2 * mid * sum + mid * mid * (r - l + 1);
}
int solve(int i, int j) {
    if (i > n)return 0;
    if (j == 0)return inf;
    if (dp[i][j] != -1)return dp[i][j];
    dp[i][j] = inf;
    for (int start = 0; i + start <= n; start++) {
        dp[i][j] = min(dp[i][j], (long long)minError(i, i + start) + solve(i + start + 1, j - 1));
    }
    return dp[i][j];
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) {
            psum[i] = psum[i - 1] + a[i];
            psum2[i] = psum2[i - 1] + a[i] * a[i];
        }
        cout << solve(1, s) << '\n';
    }
}