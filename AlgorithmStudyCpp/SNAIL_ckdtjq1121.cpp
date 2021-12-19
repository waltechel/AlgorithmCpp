#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<double>> dp;
const double P = (double)3 / 4; // rainy
const double Q = (double)1 / 4; // sunny

double rec(int cur, int rest_days)
{
    if (n <= cur)
        return 1;

    if (rest_days == 0)
        return 0;

    double& ret = dp[cur][rest_days];
    if (ret != -1)
        return ret;

    return ret = P * rec(cur + 2, rest_days - 1) + Q * rec(cur + 1, rest_days - 1);
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
        cin >> n >> m;

        dp = vector<vector<double>>(n + 1, vector<double>(m + 1, -1));

        cout.fixed;
        cout.precision(10);
        cout << rec(0, m) << "\n";
    }
}