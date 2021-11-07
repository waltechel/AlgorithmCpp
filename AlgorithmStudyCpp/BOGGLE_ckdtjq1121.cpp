#include <bits/stdc++.h>

using namespace std;

vector<string> grid;
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int dp[5][5][10];
vector<string> tofind;
bool find(int s, int idx, int y, int x)
{
    // out of array idx
    if (y < 0 || y >= 5 || x < 0 || x >= 5)
        return 0;

    // find string
    if (idx == tofind[s].size())
        return 1;

    int& ret = dp[y][x][idx];

    if (ret != -1)
        return ret;

    // mismatch tofind string
    if (grid[y][x] != tofind[s][idx])
        return ret = 0;

    ret = 0;
    for (int i = 0; i < 8; i++)
    {
        ret = ret || find(s, idx + 1, y + dy[i], x + dx[i]);
    }

    return ret;
}
bool findAll(int s, int idx)
{
    // brute force every idx to start point
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            memset(dp, -1, sizeof(dp));
            if (find(s, idx, i, j))
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        grid = vector<string>(5);
        for (int i = 0; i < 5; i++)
            cin >> grid[i];

        int n;
        cin >> n;

        tofind = vector<string>(n);
        for (int i = 0; i < n; i++)
            cin >> tofind[i];

        for (int i = 0; i < n; i++)
        {

            bool ans = findAll(i, 0);

            if (ans)
                cout << tofind[i] << " YES\n";
            else
                cout << tofind[i] << " NO\n";
        }
    }
}
