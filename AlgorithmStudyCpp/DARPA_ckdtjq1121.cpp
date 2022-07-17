#include <bits/stdc++.h>

using namespace std;

vector<double> a;

// loc idx의 location 중에 cam개의 camera를 사용해서 모든 거리가  gap 이상이 가능한가?
bool decision(int cam, double gap)
{
    double limit = -1;
    int installed = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (limit <= a[i])
        {
            limit = a[i] + gap;
            installed++;
        }
    }

    return installed >= cam;
}

double optimize(int cam)
{
    double left = 0, right = 241;

    for (int iter = 0; iter < 100; iter++)
    {
        double mid = (left + right) / 2.0;

        if (decision(cam, mid))
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
        int n, m;
        cin >> n >> m;

        a = vector<double>(m);
        for (int i = 0; i < m; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        cout << fixed << setprecision(2);
        cout << optimize(n) << "\n";
    }
}