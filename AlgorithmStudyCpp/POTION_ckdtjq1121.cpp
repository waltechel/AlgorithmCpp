#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);

    int tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n;
        cin >> n;

        vector<int> r(n), p(n);
        for (int i = 0; i < n; i++)
            cin >> r[i];

        for (int i = 0; i < n; i++)
            cin >> p[i];

        int g = 0;
        for(int i = 0; i < n; i++)
        {
            g = gcd(g, r[i]);
            g = gcd(g, p[i]);
        }

        double minDoubleForPlus = 0; // non-minus
        for (int i = 0; i < n; i++)
        {
            if (minDoubleForPlus < (double)p[i] / r[i])
                minDoubleForPlus = (double)p[i] / r[i];
        }

        // var + p[i] = r[i] * k
        // k = g * Non-minus
        int minIntForPlus = ceil(g * minDoubleForPlus);  // non-minus

        for(int i = 0; i < n; i++)
            cout << r[i]* minIntForPlus / g - p[i] << " ";
        cout << "\n";
    }
}

// r[i] = 4 6 2 4
// p[i] = 6 4 2 4
// ans[i] = 0 5 1 2

// x = 4n - 6 = 2(2n-3)
// y = 6n - 4 = 2(3n-2)
// z = 2n - 2 = 2(n-1)
// w = 4n - 4 = 2(2n-2)

// gcd = 2
// -> 2*val 가 정수 <=> val = (1/2)*k, k는 정수

// x, y, z, w >= 0