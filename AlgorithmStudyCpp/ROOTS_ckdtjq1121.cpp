#include <bits/stdc++.h>

using namespace std;
void printV(vector<double> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}
vector<double> differential(vector<double> a)
{
    vector<double> ret;

    reverse(a.begin(), a.end());
    for (int i = 1; i < a.size(); i++)
    {
        ret.push_back(a[i] * i);
    }
    reverse(ret.begin(), ret.end());

    return ret;
}
double func(vector<double> poly, double x)
{
    reverse(poly.begin(), poly.end());
    double ret = 0;
    double digit = 1;
    for (int i = 0; i < poly.size(); i++)
    {
        ret += poly[i] * digit;
        digit *= x;
    }

    return ret;
}
vector<double> naiveSolve(vector<double> v)
{
    vector<double> ret;
    ret.push_back((-v[1] - sqrt(v[1] * v[1] - (4 * v[0] * v[2]))) / (2 * v[0]));
    ret.push_back((-v[1] + sqrt(v[1] * v[1] - (4 * v[0] * v[2]))) / (2 * v[0]));

    return ret;
}
vector<double> solve(vector<double> v)
{
    int n = v.size() - 1;

    if (n == 2)   
        return naiveSolve(v);

    vector<double> diff = differential(v);
    vector<double> range = solve(diff);
    range.insert(range.begin(), -10.0 - 1e-11);
    range.push_back(10.0 + 1e-11);

    vector<double> ret;
    for (int i = 0; i + 1 < range.size(); i++)
    {
        double left = range[i], right = range[i + 1];
        for (int j = 0; j < 100; j++)
        {
            double mid = (left + right) / 2;
            if (func(v, left) * func(v, mid) <= 0)
                right = mid;
            else
                left = mid;
        }

        ret.push_back(left);
    }

    return ret;
}
int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n;
        cin >> n;

        vector<double> v(n + 1);
        for (int i = 0; i < n + 1; i++)
            cin >> v[i];

        vector<double> ans = solve(v);

        cout << fixed << setprecision(10);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}