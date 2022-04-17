#include <bits/stdc++.h>

using namespace std;

bool decision(double n, int m, double rate, double c)
{
    for (int i = 0; i < m; i++)
    {
        n *= rate;
        n -= c;
    }

    return n > 0.0;
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
        double n, p;
        int m;
        cin >> n >> m >> p;

        double rate = (100.0 + p/12.0) / 100.0;
        cout << fixed << setprecision(10);

        // n * t^m * (t - 1) / (t^m - 1)
        // cout << n*pow(rate, m)*(rate -1) / (pow(rate, m) - 1) << "\n"; 

        double left = 0, right = n * rate;
        for (int i = 0; i < 100; i++)
        {
            double mid = (left + right) / 2;

            if (decision(n, m, rate, mid))
                left = mid;
            else
                right = mid;
        }

        cout << left << "\n";
    }
}