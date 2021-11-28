#include <bits/stdc++.h>

using namespace std;

string s, p;
vector<vector<int>> dp;

int solve(int si, int pi)
{
    // 둘다 끝 - 성공
    if (si == s.size() && pi == p.size())
        return 1;

    // 와일드 카드가 끝
    if (si == s.size() && pi != p.size())
        return 0;

    // 남은 와일드 카드의 문자가 모두 *이면 통과
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
        // *이 0개 부터 나머지 문자를 대체하는 경우 모두 탐색
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

        // 작은 것 부터 출력
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << "\n";
    }
}
