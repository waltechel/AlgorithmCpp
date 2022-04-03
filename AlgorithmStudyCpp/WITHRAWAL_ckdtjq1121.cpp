#include <bits/stdc++.h>

using namespace std;
struct input
{
    int r, c;
};

int n, k;
vector<input> a;
bool decision(double average)
{
    vector<double> v;
    for (int i = 0; i < n; i++)
        v.push_back(average * a[i].c - a[i].r);
    sort(v.begin(), v.end());

    double sum = 0;
    for (int i = n - k; i < n; i++)
        sum += v[i];

    return sum >= 0; // average가 크다
}
int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        cin >> n >> k;

        a = vector<input>(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].r >> a[i].c;

        double left = -1e-11, right = 1 + 1e-11;
        for (int j = 0; j < 100; j++)
        {
            double mid = (left + right) / 2;

            if(!decision(mid)) 
                left = mid;
            else
                right = mid;
        }
        cout << fixed << setprecision(10);
        cout << left << "\n";
    }
}