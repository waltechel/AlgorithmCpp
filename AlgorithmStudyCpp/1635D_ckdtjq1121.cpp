#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int MOD = 1e9 + 7;

map<int, int> visited;
bool is_visited(int x)
{
    int tmp = x;
    while (tmp)
    {
        if (visited[tmp])
            return true;

        if (tmp & 1)
        {
            tmp >>= 1;
        }
        else if ((tmp & 3) == 0)
        {
            tmp >>= 2;
        }
        else
            break;
    }

    return false;
}

vector<int> dp;
int rec(int n)
{
    if (n == 1)
        return 1;

    if (n == 2)
        return 2;

    int &ret = dp[n];

    if (ret != -1)
        return ret;

    return ret = (rec(n - 1) + rec(n - 2)) % MOD;
}

vector<int> ans;
int getAnswer(int x, int p)
{
    int x_size = 0;
    int tmp = x;
    while (tmp)
    {
        x_size++;
        tmp >>= 1;
    }

    if (p - x_size < 0)
        return 0;

    int &ret = ans[p - x_size];
    if (ret != -1)
        return ret;

    ret = 1;
    for (int i = 1; i <= p - x_size; i++)
        ret = (ret + rec(i)) % MOD;

    return ret;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, p;
    cin >> n >> p;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    dp = vector<int>(p + 1, -1);
    ans = vector<int>(p + 1, -1);

    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (!is_visited(a[i])) // 기존에 없던 경우의 수
        {
            ret = (ret + getAnswer(a[i], p)) % MOD;
            visited[a[i]]++; // map
        }
    }

    cout << ret << "\n";
}