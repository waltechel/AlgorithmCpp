#include <bits/stdc++.h>

using namespace std;

string s, p;
vector<vector<int>> dp;

int solve(int si, int pi)
{
    // �Ѵ� �� - ����
    if (si == s.size() && pi == p.size())
        return 1;

    // ���ϵ� ī�尡 ��
    if (si == s.size() && pi != p.size())
        return 0;

    // ���� ���ϵ� ī���� ���ڰ� ��� *�̸� ���
    if (si != s.size() && pi == p.size())
    {
        for (int i = si; i < s.size(); i++)
        {
            if (s[i] != '*')
                return 0;
        }
        return 1;
    }

    int& ret = dp[si][pi];

    if (ret != -1)
        return ret;

    ret = 0;
    if (s[si] == '?' || s[si] == p[pi])
        ret = solve(si + 1, pi + 1);
    else if (s[si] == '*')
    {
        // *�� 0�� ���� ������ ���ڸ� ��ü�ϴ� ��� ��� Ž��
        for (int i = pi; i <= p.size(); i++)
            ret = ret || solve(si + 1, i);
    }
    else
        ret = 0;

    return ret;
}
int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        cin >> s;

        int n;
        cin >> n;

        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            cin >> p;

            dp = vector<vector<int>>(s.size(), vector<int>(p.size(), -1));
            if (solve(0, 0))
                ans.push_back(p);
        }

        // ���� �� ���� ���
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << "\n";
    }
}
