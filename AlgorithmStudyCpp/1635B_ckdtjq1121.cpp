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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> mIdx; // max point index
        for (int i = 1; i + 1 < n; i++)
        {
            if (a[i - 1] < a[i] && a[i] > a[i + 1])
                mIdx.push_back(i);
        }

        int ans = 0;
        for (int i = 0; i < mIdx.size(); i++)
        {
            int j = mIdx[i];
            if (i + 1 < mIdx.size() && mIdx[i] + 2 == mIdx[i + 1])
            {
                ans++;
                a[j + 1] = max(a[j], a[j + 2]);
                i++;
            }
            else
            {
                ans++;
                a[j] = max(a[j + 1], a[j - 1]);
            }
        }

        cout << ans << "\n";
        for(int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << "\n";
    }
}