#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 12 + 100 + 2;
const int INF = 1 << 30;

//capacity �迭
int c[MAX_V][MAX_V];
//flow �迭
int f[MAX_V][MAX_V];
//�� node�� parent�� ������ �迭
int parent[MAX_V];

int fordFulkerson(int source, int sink)
{
    int total = 0;

    while (true)
    {
        memset(parent, -1, sizeof(parent));
        queue<int> Q;
        Q.push(source);
        parent[source] = source;

        while (!Q.empty() && parent[sink] == -1)
        {
            int here = Q.front();
            Q.pop();
            for (int there = 0; there < MAX_V; there++)
            {
                // �湮���� �ʴ� ��� �� ������ ���� ���� ���� ��θ� �����.
                if (c[here][there] - f[here][there] > 0 && parent[there] == -1)
                {
                    parent[there] = here;
                    Q.push(there);
                }
            }
        }

        //��� ��θ� �� ã�� ����.
        if (parent[sink] == -1)
            break;

        int mn = INF;
        //�ּ� ������ ã���ϴ�.
        for (int p = sink; p != source; p = parent[p])
        {
            mn = min(c[parent[p]][p] - f[parent[p]][p], mn);
        }
        //�ּ� ������ŭ �߰��մϴ�.
        for (int p = sink; p != source; p = parent[p])
        {
            f[parent[p]][p] += mn;
            f[p][parent[p]] -= mn;
        }
        total += mn;
    }
    return total;
}

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int n, m;
        cin >> n >> m;

        // ������ ���� �¼�
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // u�� v�� �ο� ���
        vector<pair<int, int>> fight(m);
        for (int i = 0; i < m; i++)
            cin >> fight[i].first >> fight[i].second;

        int sz = n + m + 2;

        // start : 0, ��� : 1 ~ m , ���� : m + 1 ~ m+n, end (0): m+n+1, end (else) : m+n+2
        // start -> ���
        for (int i = 1; i <= m; i++)
            c[0][i] = 1;
        // ��� -> ����
        for (int i = 0; i < m; i++)
        {
            int match = i + 1;
            int a = fight[i].first;
            int b = fight[i].second;
            a += m + 1, b += m + 1;
            c[match][a] = 1;
            c[match][b] = 1;
        }
        // ���� -> end
        int ret = -1;
        for (int i = 0; i <= m; i++)
        {
            // 0��° ������ i���� ���� �� �ܵ� ��� ������ ���
            int w = a[0] + i;

            int sum = i;
            vector<int> gap(n);
            for (int j = 1; j < n; j++)
            {
                // 1 ~ n-1 ������ �ִ� gap[j]��� ��ŭ �¸� ����
                gap[j] = w - a[j] - 1;
                sum += gap[j];
            }
            // ��� ��⸦ ġ���� ����
            if (sum < m)
                continue;

            int end = m + n + 1;
            c[m + 1][end] = i;
            for (int j = m + 2; j <= m + n; j++)
            {
                c[j][end] = gap[j - (m + 1)];
            }

            // 0�� W�� ä���� ���ϴ� ��찡 ����    
            memset(f, 0, sizeof(f));
            // ġ��� �ִ� �ִ� ��� ��
            ret = fordFulkerson(0, m + n + 1);

            if (ret == m)
            {
                cout << a[0] + i << "\n";
                break;
            }
        }

        if (ret != m)
            cout << -1 << "\n";
    }
}
