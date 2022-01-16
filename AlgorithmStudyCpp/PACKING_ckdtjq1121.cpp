#include <bits/stdc++.h>

using namespace std;

int n, w;
const int INF = -10000000;

vector<pair<string, pair<int, int>>> arr; // name, weight, value
vector<vector<int>> dp;

int rec(int idx, int capacity)
{
    // �ȵǴ� ����� ��
    if (capacity < 0)
        return INF; // -10000000

    // ��
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
    // idx ��° ������ ���� �Ȱ��� �ִ� ���ڵ��� ���ٸ� ���� �ʴ´�.  
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

        dp = vector<vector<int>>(n, vector<int>(w + 1, -1)); // n��° ���������� w���Ը� ������� ���� �ִ� value
        vector<int> picked;

        backTracking(0, w, picked);
        cout << rec(0, w) << " " << picked.size() << "\n";
        for (int i = 0; i < picked.size(); i++)
            cout << arr[picked[i]].first << "\n";
    }
}