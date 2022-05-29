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

        if (is_sorted(a.begin(), a.end()))
        {
            cout << 0 << "\n";
            continue;
        }

        // [i+1, n-1] 까지 정렬이 되어 있다 -> 구간의 가장 큰 차이는 a[i+1] - a[n-1]
        vector<pair<int, pair<int, int>>> oper;
        for (int i = n-3; i >= 0; i--)
        {
            if(a[i+1] - a[n-1] < a[i])
            {
                a[i] = a[i+1] - a[n-1];
                oper.push_back({i, {i + 1, n-1}});
            }
        }

        if(!is_sorted(a.begin(), a.end()))
        {
            cout << -1 << "\n";
            continue;
        }
        
        cout << oper.size() << "\n";
        for(int i = 0; i < oper.size(); i++)
        {
            cout << oper[i].first + 1 << " " << oper[i].second.first + 1 << " " << oper[i].second.second + 1 << "\n";
        }
    }
}