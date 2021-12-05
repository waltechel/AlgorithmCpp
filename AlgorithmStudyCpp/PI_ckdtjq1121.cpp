#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> dp;

const int INF = 100001;

int fuc(int start, int end)
{
    // 모든 숫자가 같을 때 (예: 333, 5555) 난이도: 1
    int finish = 1;
    for (int i = start + 1; i <= end; i++)
        if (s[start] != s[i])
            finish = 0;
    if (finish)
        return 1;

    // 숫자가 1씩 단조 증가하거나 단조 감소할 때 (예: 23456, 3210) 난이도: 2
    finish = 1;
    int d = s[start] - s[start + 1];
    if (abs(d) == 1)
    {
        for (int i = start; i + 1 <= end; i++)
        {
            if (d != s[i] - s[i + 1])
                finish = 0;
        }
        if (finish)
            return 2;
    }
    // 숫자가 등차 수열을 이룰 때 (예: 147, 8642) 난이도: 5
    else
    {
        for (int i = start + 1; i + 1 <= end; i++)
        {
            if (s[i] - s[i + 1] != d)
                finish = 0;
        }
        if (finish)
            return 5;
    }

    // 두 개의 숫자가 번갈아 가며 출현할 때 (예: 323, 54545) 난이도: 4
    finish = 1;
    for (int i = start; i <= end; i++)
    {
        if (i % 2 == start % 2)
        {
            if (s[i] != s[start])
                finish = 0;
        }
        else
        {
            if (s[i] != s[start + 1])
                finish = 0;
        }
    }
    if (finish)
        return 4;

    // 그 외의 경우 난이도: 10
    return 10;
}
int rec(int idx)
{
    if (idx == 0)
        return 0;

    // 범위 밖
    if (idx < 0)
        return INF;

    int &ret = dp[idx];

    if (ret != -1)
        return ret;

    ret = INF;
    for (int i = 3; i <= 5; i++)
        ret = min(ret, rec(idx - i) + fuc(idx - i, idx - 1));

    return ret;
}
int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        cin >> s;

        dp = vector<int>(s.size() + 1, -1);

        cout << rec(s.size()) << "\n";
    }
}