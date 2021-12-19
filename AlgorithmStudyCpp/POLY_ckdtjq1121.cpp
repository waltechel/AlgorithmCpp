#include <bits/stdc++.h>

using namespace std;

const int MOD = 10000000;
vector<vector<int>> dp;

// n개 중 first 개를 이번에 사용을 하겠다
int rec(int n, int first)
{
    if (n == first)
        return 1;

    int& ret = dp[n][first];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int second = 1; second <= n - first; second++)
    {
        // first 개수의 블록과 second 개수의 블록이 만들수 있는 경우의 수 (second + first - 1)
        ret += ((second + first - 1) * rec(n - first, second)) % MOD;
        ret %= MOD;
    }

    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n;
        cin >> n;

        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += rec(n, i);
            ans %= MOD;
        }

        cout << ans << "\n";
    }
}