#include <bits/stdc++.h>

using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
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
        int n;
        cin >> n;

        vector<pair<int, int>> time(n); // {micro, eat}
        for (int i = 0; i < n; i++)
            cin >> time[i].first;

        for (int i = 0; i < n; i++)
            cin >> time[i].second;

        sort(time.begin(), time.end(), compare);

        int ans = 0;
        int eating = 0;
        for (int i = 0; i < n; i++)
        {
            ans += time[i].first; // microwave time

            // longest time to eat from now on
            if (time[i].first < eating)
                eating = max(eating - time[i].first, time[i].second);
            else// time[i].first <= eating
                eating = time[i].second;
        }

        cout << ans + eating << "\n";
    }
}