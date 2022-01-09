#include <bits/stdc++.h>

using namespace std;

int n, w;
const int INF = -10000000;

vector<pair<string, pair<int, int>>> arr; // name, weight, value
vector<vector<int>> dp;

int rec(int idx, int capacity)
{
    // 안되는 경우의 수
    if (capacity < 0)
        return INF; // -10000000

    // 끝
    if (idx >= n)
        return 0;

    int& ret = dp[idx][capacity];

    if (ret != -1)
        return ret;

    int notAdd = rec(idx + 1, capacity);
    int add = rec(idx + 1, capacity - arr[idx].second.first) + arr[idx].second.second;

    return ret = max(notAdd, add);
}

void backTracking(int idx, int capacity, vector<int>& picked)
{
    if (idx >= n)
        return;
    // idx 번째 물건을 고르나 안고르나 최대 절박도가 같다면 고르지 않는다.  
    if (rec(idx, capacity) == rec(idx + 1, capacity))
        backTracking(idx + 1, capacity, picked);
    else
    {
        picked.push_back(idx);
        backTracking(idx + 1, capacity - arr[idx].second.first, picked);
    }
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
        cin >> n >> w;

        arr = vector<pair<string, pair<int, int>>>(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second; // name, weight, value

        dp = vector<vector<int>>(n, vector<int>(w + 1, -1)); // n번째 아이템으로 w무게를 만들었을 때의 최대 value
        vector<int> picked;

        backTracking(0, w, picked);
        cout << rec(0, w) << " " << picked.size() << "\n";
        for (int i = 0; i < picked.size(); i++)
            cout << arr[picked[i]].first << "\n";
    }
}