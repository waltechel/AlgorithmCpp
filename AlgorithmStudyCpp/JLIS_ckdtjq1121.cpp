#include <bits/stdc++.h>

using namespace std;
int n, m;
const int NEGINF = INT_MIN;
vector<vector<int>> dp;
vector<int> a, b;
int rec(int ai, int bi)
{
    int& ret = dp[ai + 1][bi + 1];

    if (ret != -1)
        return ret;

    // 중복 원소 처리가 안됨..
    // int mi = min(a[ai], b[bi]);
    // ret = 2;
    // for (int i = 0; i < ai; i++)
    //     if (a[i] < mi)
    //         ret = max(ret, rec(i, bi) + 1);

    // for (int i = 0; i < bi; i++)
    //     if (b[i] < mi)
    //         ret = max(ret, rec(ai, i) + 1);


    // 종만북 코드
    ret = 0;
    int aa = (ai == -1) ? NEGINF : a[ai];
    int bb = (bi == -1) ? NEGINF : b[bi];
    int mx = max(aa, bb);
    for (int i = ai + 1; i < n; i++)
        if (mx < a[i])
            ret = max(ret, rec(i, bi) + 1);

    for (int i = bi + 1; i < m; i++)
        if (mx < b[i])
            ret = max(ret, rec(ai, i) + 1);

    return ret;
}

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        cin >> n >> m;

        a = vector<int>(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        b = vector<int>(m);
        for (int i = 0; i < m; i++)
            cin >> b[i];

        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));

        cout << rec(-1, -1) << "\n";
    }
}
