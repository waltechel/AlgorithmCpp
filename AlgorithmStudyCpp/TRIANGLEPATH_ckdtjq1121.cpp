#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n;
        cin >> n;

        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                cin >> dp[i][j];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0) // 맨 첫 점은 위에서 밖에 못내려온다
                    dp[i][j] += dp[i - 1][j];
                else if (j == i) // 맨 끝점은 왼쪽 위에서 밖에 못내려 온다
                    dp[i][j] += dp[i - 1][j - 1];
                else // 나머지는 두가지 중 최대가 되는 경로를 선택한다.
                    dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[n - 1][i]);

        cout << ans << "\n";
    }
}
