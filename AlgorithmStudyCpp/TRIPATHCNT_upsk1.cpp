#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int MAX[101][101], dp[101][101];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cin >> a[i][j];
                MAX[i][j] = a[i][j];
            }
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (MAX[i][j] < MAX[i - 1][j - 1] + a[i][j]) {
                    MAX[i][j] = MAX[i - 1][j - 1] + a[i][j];
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (MAX[i][j] < MAX[i - 1][j] + a[i][j]) {
                    MAX[i][j] = MAX[i - 1][j] + a[i][j];
                    dp[i][j] = dp[i - 1][j];
                }
                else if (MAX[i][j] == MAX[i - 1][j] + a[i][j]) {
                    dp[i][j] += dp[i - 1][j];
                }
            }
        }
        int ans = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            if (ans < MAX[n][i]) {
                ans = MAX[n][i];
                sum = dp[n][i];
            }
            else if (ans == MAX[n][i]) {
                sum += dp[n][i];
            }
        }
        cout << sum << '\n';
    }
}