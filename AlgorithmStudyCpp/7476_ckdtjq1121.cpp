// not yet solved backtracking
#include <bits/stdc++.h>

using namespace std;
#define int int64_t
int n, m;
vector<int> a, b;

// vector<int> parent;
// vector<int> ans;

vector<vector<int>> dp;
int rec(int ai, int bi)
{
    if (ai == n + 1 || bi == m + 1)
        return 0;

    int& ret = dp[ai][bi];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = ai + 1; i <= n; i++)
    {
        if (a[ai] >= a[i])
            continue;

        for (int j = bi + 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                ret = max(ret, rec(i, j) + 1);
            }
        }
    }

    return ret;
}

// https://www.geeksforgeeks.org/longest-common-increasing-subsequence-lcs-lis/
int LCIS()
{
    // b[j]번째 원소를 사용해서 가질 수 있는 최대 LCIS
    vector<int> table(m + 1);
    for (int j = 1; j <= m; j++)
        table[j] = 0;

    for (int i = 1; i <= n; i++)
    {
        int current = 0;

        for (int j = 1; j <= m; j++)
        {
            // dp 갱신
            if (a[i] == b[j])
                if (current + 1 > table[j])
                    table[j] = current + 1;

            // a[i] 보다 b[j]가 작은 값이라면 현재의 LCIS는 b[j]의 값이다.
            if (a[i] > b[j])
                if (table[j] > current)
                    current = table[j];
        }
    }

    // max value of LCIS
    int result = 0;
    for (int i = 1; i <= m; i++)
        if (table[i] > result)
        {
            result = table[i];
        }

    return result;
}

int32_t main()
{
    cin >> n;
    a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cin >> m;
    b = vector<int>(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
    cout << LCIS() << " " << rec(0, 0) << "\n";
}