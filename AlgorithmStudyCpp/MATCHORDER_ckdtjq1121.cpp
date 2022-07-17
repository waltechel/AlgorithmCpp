#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n;
        cin >> n;

        vector<int> rus(n);
        for (int i = 0; i < n; i++)
            cin >> rus[i];

        vector<int> kor(n);
        for (int i = 0; i < n; i++)
            cin >> kor[i];

        sort(rus.begin(), rus.end());
        sort(kor.begin(), kor.end());

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int cand = 0;
            for (int j = 0; i + j < n; j++)
            {
                if (rus[j] <= kor[i + j])
                    cand++;
            }

            ans = max(ans, cand);
        }

        cout << ans << "\n";
    }
}