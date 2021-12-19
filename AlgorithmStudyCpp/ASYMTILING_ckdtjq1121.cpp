#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
vector<int> dp;
int rec(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    int& ret = dp[n];
    if (ret != -1)
        return ret;

    return ret = (rec(n - 1) + rec(n - 2)) % MOD;
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

        dp = vector<int>(n + 1, -1);

        if (n % 2)
            cout << ((rec(n) - rec(n / 2)) + MOD) % MOD << "\n";
        else
            cout << ((rec(n) - rec(n / 2 + 1)) + MOD) % MOD << "\n";
    }
}