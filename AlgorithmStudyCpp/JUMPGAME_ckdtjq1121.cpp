#include <bits/stdc++.h>

using namespace std;

int n;

vector<vector<int>> grid;
vector<vector<int>> dp;

// (y, x) -> (n-1, n-1) 로 갈 수 있는가
int solve(int y, int x)
{
    // 끝에 도달한 경우
    if (y == n - 1 && x == n - 1)
        return 1;

    // 범위 밖으로 나가는 경우
    if (y >= n || x >= n)
        return 0;

    int& ret = dp[y][x];

    if (ret != -1)
        return ret;

    // || 를 사용 하면 전자가 참이면 후자는 탐색하지 않는다 -> 더 빠르다
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

        int ans = solve(0, 0); // 0,0에서 n-1,n-1까지 도달이 가능한가

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
