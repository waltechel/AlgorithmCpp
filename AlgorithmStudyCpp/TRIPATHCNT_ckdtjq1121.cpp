#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> grid;
vector<vector<int>> dp;
int n;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        cin >> n;

        grid = vector<vector<int>>(n, vector<int>(n));
        dp = vector<vector<int>>(n, vector<int>(n, 1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> grid[i][j];
            }
        }

        // 최대 경로 만들기
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                grid[i][j] += max(grid[i + 1][j], grid[i + 1][j + 1]);
            }
        }
        // 최대 경로 수 세기
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                if (grid[i + 1][j] > grid[i + 1][j + 1])
                    dp[i][j] = dp[i + 1][j];
                else if (grid[i + 1][j] < grid[i + 1][j + 1])
                    dp[i][j] = dp[i + 1][j + 1];
                else
                    dp[i][j] = dp[i + 1][j] + dp[i + 1][j + 1];
            }
        }

        cout << dp[0][0] << "\n";
    }
}