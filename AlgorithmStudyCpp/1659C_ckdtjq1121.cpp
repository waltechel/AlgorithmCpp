#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        vector<int> dist(n);

        for (int i = 0; i < n; i++)
            cin >> dist[i];

        // a : move, b : conquer

        int ans = 0;
        int here = 0;

        if (a < b)
        {
            for (int i = 0; i < n; i++)
            {
                ans += (dist[i] - here) * b; 
                if (i != n - 1) 
                    ans += (dist[i] - here) * a;
                here = dist[i];
            }
        }
        else 
        {
            for (int i = 0; i < n; i++)
            {
                ans += (dist[i] - here) * b;
                if (a <= b * (n - 1 - i))
                {
                    ans += (dist[i] - here) * a;
                    here = dist[i];
                }
            }
        }

        cout << ans << "\n";
    }
}