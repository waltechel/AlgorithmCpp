#include <bits/stdc++.h>

using namespace std;
int n, m;

int rate(long long total, long long win)
{
    return 100 * win / total;
}

bool decision(long long extra)
{
    return rate(n, m) != rate(n + extra, m + extra);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        cin >> n >> m;

        int left = 1, right = 1000000000;
        while (left <= right)
        {
            long long mid = (left + right) / 2;

            if (decision(mid))
                right = mid -1;
            else
                left = mid + 1;
        }

        if (left == 1000000000 + 1)
            cout << -1 << "\n";
        else
            cout << left << "\n";
    }
}