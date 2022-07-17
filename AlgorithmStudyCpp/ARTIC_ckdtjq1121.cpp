#include <bits/stdc++.h>

using namespace std;

vector<pair<double, double>> a;

bool decision(double gap) // gap 이하로 모두 통신이 되는가
{
    queue<int> q;
    vector<bool> check(a.size(), false);

    q.push(0);
    check[0] = true;

    while(!q.empty())
    {
        int j = q.front();
        q.pop();

        for(int i = 0; i < a.size(); i++)
        {
            if(!check[i])
            {
                double dist = (a[i].first - a[j].first) * (a[i].first - a[j].first) +
                (a[i].second - a[j].second) * (a[i].second - a[j].second);
                
                dist = sqrt(dist);

                if(dist <= gap)
                {
                    check[i] = true;
                    q.push(i);
                }
            }
        }
    }
 
    for(int i = 0; i < a.size(); i++)
        if(!check[i])
            return false;

    return true;
}

double optimize(void)
{
    double left = 0, right = 1000 * 1.5; // 1000 * sqrt(2)

    for (int i = 0; i < 100; i++)
    {
        double mid = (left + right) / 2;

        if (!decision(mid))
            left = mid;
        else
            right = mid;
    }
    return left;
}

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n;
        cin >> n;

        a = vector<pair<double, double>>(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second; // x, y
        }

        cout << fixed << setprecision(2);
        cout << optimize() << "\n";
    }
}