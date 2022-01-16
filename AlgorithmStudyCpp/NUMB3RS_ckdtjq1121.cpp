#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > adj;
vector<vector<double> > dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n, d, p;
        cin >> n >> d >> p;

        adj = vector<vector<int> >(n, vector<int>(n));
        vector<int> cnt_ways(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> adj[i][j];

                if (adj[i][j])
                    cnt_ways[i]++;
            }
        }

        dp = vector<vector<double> >(n, vector<double>(d + 1, 0));
        dp[p][0] = 1; // 0일차에 p에 있을 확률 1/1

        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (adj[j][k])
                        dp[k][i + 1] += dp[j][i] * (1.0 / cnt_ways[j]);
                }
            }
        }

        // p에서 출발하여 d일 뒤에 arrive 마을에 있을 확률 계산하기

        int q;
        cin >> q;

        cout.fixed;
        cout.precision(12);
        for (int i = 0; i < q; i++)
        {
            int arrive;
            cin >> arrive;

            cout << dp[arrive][d] << " ";
        }
        cout << "\n";

        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j <= d; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }
}