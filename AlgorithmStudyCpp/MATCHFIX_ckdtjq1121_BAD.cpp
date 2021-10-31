#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 12 + 100 + 2;
const int INF = 1 << 30;

//capacity 배열
int c[MAX_V][MAX_V];
//flow 배열
int f[MAX_V][MAX_V];
//각 node의 parent를 저장할 배열
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
                // 방문하지 않는 노드 중 유량이 남은 노드로 가서 경로를 만든다.
                if (c[here][there] - f[here][there] > 0 && parent[there] == -1)
                {
                    parent[there] = here;
                    Q.push(there);
                }
            }
        }

        //모든 경로를 다 찾고 끝냄.
        if (parent[sink] == -1)
            break;

        int mn = INF;
        //최소 유량을 찾습니다.
        for (int p = sink; p != source; p = parent[p])
        {
            mn = min(c[parent[p]][p] - f[parent[p]][p], mn);
        }
        //최소 유량만큼 추가합니다.
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

        // 선수의 현재 승수
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // u와 v가 싸움 경기
        vector<pair<int, int>> fight(m);
        for (int i = 0; i < m; i++)
            cin >> fight[i].first >> fight[i].second;

        int sz = n + m + 2;

        // start : 0, 경기 : 1 ~ m , 선수 : m + 1 ~ m+n, end (0): m+n+1, end (else) : m+n+2
        // start -> 경기
        for (int i = 1; i <= m; i++)
            c[0][i] = 1;
        // 경기 -> 선수
        for (int i = 0; i < m; i++)
        {
            int match = i + 1;
            int a = fight[i].first;
            int b = fight[i].second;
            a += m + 1, b += m + 1;
            c[match][a] = 1;
            c[match][b] = 1;
        }
        // 선수 -> end
        int ret = -1;
        for (int i = 0; i <= m; i++)
        {
            // 0번째 선수가 i승을 했을 때 단독 우승 가능한 경우
            int w = a[0] + i;

            int sum = i;
            vector<int> gap(n);
            for (int j = 1; j < n; j++)
            {
                // 1 ~ n-1 까지는 최대 gap[j]경기 만큼 승리 가능
                gap[j] = w - a[j] - 1;
                sum += gap[j];
            }
            // 모든 경기를 치루지 못함
            if (sum < m)
                continue;

            int end = m + n + 1;
            c[m + 1][end] = i;
            for (int j = m + 2; j <= m + n; j++)
            {
                c[j][end] = gap[j - (m + 1)];
            }

            // 0가 W을 채우지 못하는 경우가 생김    
            memset(f, 0, sizeof(f));
            // 치룰수 있는 최대 경기 수
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
