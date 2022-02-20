#include <bits/stdc++.h>

using namespace std;
const int INF = -987654321; // 50 * 1000 �� �̻��� INF �̴�
vector<int> a;
vector<vector<vector<int>>> dp;

// [start, end] turn(0 = ����, 1 = ����)
int rec(int start, int end, int turn)
{
    if (end < start) // ������ ����
        return 0;

    int& ret = dp[start][end][turn];
    if (ret != INF)
        return ret;

    int nextTurn = (turn ^ 1);
    int getOne; // 1���� ���� ������
    getOne = max(a[start] - rec(start + 1, end, nextTurn), a[end] - rec(start, end - 1, nextTurn));

    if (start + 1 <= end)
    {
        int remove = 0; // 2�� �̻� �������� 2�� �����ϱ� - ������ �ּ� ������ ��� �ϴ°��� �ּ�
        remove = max(0 - rec(start + 2, end, nextTurn), 0 - rec(start, end - 2, nextTurn));

        ret = max(remove, getOne);
    }
    else
        ret = getOne;

    return ret;
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

        a = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // dp[i][j][k] : k = ���� | ����, [i,j]�� ���ڰ� �������� k�� (k^1) �� ���� ��
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(2, INF)));

        cout << rec(0, n - 1, 0) << "\n";
    }
}