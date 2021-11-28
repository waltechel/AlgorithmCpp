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
                if (j == 0) // �� ù ���� ������ �ۿ� �������´�
                    dp[i][j] += dp[i - 1][j];
                else if (j == i) // �� ������ ���� ������ �ۿ� ������ �´�
                    dp[i][j] += dp[i - 1][j - 1];
                else // �������� �ΰ��� �� �ִ밡 �Ǵ� ��θ� �����Ѵ�.
                    dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[n - 1][i]);

        cout << ans << "\n";
    }
}
