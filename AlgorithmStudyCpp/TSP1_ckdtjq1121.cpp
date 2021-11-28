#include <bits/stdc++.h>

using namespace std;

int n;
const double DNF = DBL_MAX;

vector<vector<double>> dist;
double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength)
{
    // 해당 경로의 끝
    if (path.size() == n)
        return currentLength;

    // 가지 않은 경로 들 중 갈 수 있는 최단 경로
    double ret = DNF;
    for (int next = 0; next < n; next++)
    {
        if (visited[next])
            continue;

        int here = path.back();

        path.push_back(next);
        visited[next] = true;

        double cand = shortestPath(path, visited, currentLength + dist[here][next]);
        ret = min(ret, cand);

        visited[next] = false;
        path.pop_back();
    }

    return ret;
}

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        cin >> n;

        dist = vector<vector<double>>(n, vector<double>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> dist[i][j];

        double ans = DBL_MAX;
        for (int i = 0; i < n; i++)
        {
            vector<int> path(1, i);
            vector<bool>visited(n, 0);
            visited[i] = 1;
            ans = min(ans, shortestPath(path, visited, 0.0));
        }

        cout.fixed;
        cout.precision(15);
        cout << ans << "\n";
    }
}
