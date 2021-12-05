#include <bits/stdc++.h>

using namespace std;

int n;

vector<vector<int>> grid;
vector<vector<int>> dp;

// (y, x) -> (n-1, n-1) �� �� �� �ִ°�
int solve(int y, int x)
{
    // ���� ������ ���
    if (y == n - 1 && x == n - 1)
        return 1;

    // ���� ������ ������ ���
    if (y >= n || x >= n)
        return 0;

    int& ret = dp[y][x];

    if (ret != -1)
        return ret;

    // || �� ��� �ϸ� ���ڰ� ���̸� ���ڴ� Ž������ �ʴ´� -> �� ������
    return ret = solve(y + grid[y][x], x) || solve(y, x + grid[y][x]);
}

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        cin >> n;

        grid = vector<vector<int>>(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];

        dp = vector<vector<int>>(n, vector<int>(n, -1));

        int ans = solve(0, 0); // 0,0���� n-1,n-1���� ������ �����Ѱ�

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
