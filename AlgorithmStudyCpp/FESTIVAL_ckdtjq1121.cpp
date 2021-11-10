#include <bits/stdc++.h>

using namespace std;

int n, l;
const int INF = 987654321;

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        cin >> n >> l;
        l--;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> psum(n);
        psum[0] = a[0];
        for (int i = 1; i < n; i++)
            psum[i] = psum[i - 1] + a[i];

        double ans = INT_MAX;
        double sum;

        // [i, j] average cost - brute force
        for (int i = 0; i < n; i++)
        {
            for (int j = i + l; j < n; j++)
            {
                if (i > 0)
                    sum = psum[j] - psum[i - 1];
                else
                    sum = psum[j];

                double cand = sum / (j - i + 1);
                if (ans - cand > 1e-8) // 1e-8 > error
                    ans = cand;
            }
        }

        cout.fixed;
        cout.precision(15);
        cout << ans << "\n";
    }
}