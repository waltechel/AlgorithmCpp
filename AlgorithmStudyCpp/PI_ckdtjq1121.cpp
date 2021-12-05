#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> dp;

const int INF = 100001;

int fuc(int start, int end)
{
    // ��� ���ڰ� ���� �� (��: 333, 5555) ���̵�: 1
    int finish = 1;
    for (int i = start + 1; i <= end; i++)
        if (s[start] != s[i])
            finish = 0;
    if (finish)
        return 1;

    // ���ڰ� 1�� ���� �����ϰų� ���� ������ �� (��: 23456, 3210) ���̵�: 2
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
    // ���ڰ� ���� ������ �̷� �� (��: 147, 8642) ���̵�: 5
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

    // �� ���� ���ڰ� ������ ���� ������ �� (��: 323, 54545) ���̵�: 4
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

    // �� ���� ��� ���̵�: 10
    return 10;
}
int rec(int idx)
{
    if (idx == 0)
        return 0;

    // ���� ��
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