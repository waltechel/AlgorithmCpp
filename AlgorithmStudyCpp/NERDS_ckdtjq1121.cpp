#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> nerd;
vector<pair<int, int>> normal;
vector<pair<int, int>> convexHull;
vector<pair<int, int>> convexHull2;

pair<double, double> normalizeVector(double dx, double dy)
{
    double size = sqrt(dx * dx + dy * dy);
    return {dx / size, dy / size};
}
// a 벡터와 b벡터가 ccw 인지 확인하는 함수
int ccw(double ax, double ay, double bx, double by)
{
    pair<double, double> a = normalizeVector(ax, ay);
    ax = a.first, ay = a.second;

    pair<double, double> b = normalizeVector(bx, by);
    bx = b.first, by = b.second;

    // double c = ax*bx + ay*by; // cos
    double s = ax * by - ay * bx; // sin

    if (s > 0)
        return 1; // ccw
    else if (s == 0)
        return 0; // none
    else if (s < 0)
        return -1; // cw
}
double dist(double ax, double ay, double bx, double by)
{
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

// group으로 convexhull 만들기
vector<pair<int, int>> makeConvexHull(vector<pair<int, int>> group)
{
    vector<pair<int,int>> convexHull;
    vector<bool> visited(group.size(), false);
    double x1 = -1, y1 = -1;
    double x2, y2, x3, y3;
    for (int i = 0; i < group.size(); i++) // convexHull 의 i+1번째 점 찾기
    {
        if (convexHull.size())
        {
            x1 = convexHull.back().first;
            y1 = convexHull.back().second;
        }

        int idx;
        for (int j = 0; j < group.size(); j++) // 사용 안한 임의의 점 -> 기준 점
            if (!visited[j])
            {
                idx = j;
                x2 = group[j].first;
                y2 = group[j].second;
                break;
            }

        for (int j = 1; j < group.size(); j++) // 사용 안한 임의의 점
        {
            if (visited[j])
                continue;

            x3 = group[j].first;
            y3 = group[j].second;
            if (ccw(x2 - x1, y2 - y1, x3 - x2, y3 - y2) == -1) // 기준 벡터의 시계방향에 있다 -> 기준점으로 변경
            {
                idx = j;
                x2 = x3;
                y2 = y3;
            }
            else if (ccw(x2 - x1, y2 - y1, x3 - x2, y3 - y2) == 0) // 기준 벡터와 같은 방향일때 가까우면 -> 기준점으로 변경
            {
                double d2 = dist(x1, y1, x2, y2);
                double d3 = dist(x1, y1, x3, y3);
                if (d2 > d3) // d2가 더 멀리있다
                {
                    idx = j;
                    x2 = x3;
                    y2 = y3;
                }
            }
        }
        visited[idx] = true;
        convexHull.push_back({x2, y2}); // 가장 시계방향에 있는 가까운 점을 추가
    }

    return convexHull;
}

// convexHull과 group을 나누는 a b t 가 존재하는가
bool solve(vector<pair<int,int>> convexHull, vector<pair<int,int>> group)
{
    double x1, y1, x2, y2, x3, y3;
    for (int i = 0; i < convexHull.size(); i++)
    {
        if (i == 0)
        {
            x1 = convexHull[convexHull.size() - 1].first;
            y1 = convexHull[convexHull.size() - 1].second;
            x2 = convexHull[0].first;
            y2 = convexHull[0].second;
        }
        else
        {
            x1 = convexHull[i - 1].first;
            y1 = convexHull[i - 1].second;
            x2 = convexHull[i].first;
            y2 = convexHull[i].second;
        }

        // group의 모든 점이 convexHull의 한 벡터보다 시계방향에 있다면 구분 지을 수 있다.
        bool fail = false;
        for (int j = 0; j < group.size(); j++)
        {
            x3 = group[j].first;
            y3 = group[j].second;

            // ccw(x2-y1, y2-y1, x3-x1, y3-y1); // same
            if (ccw(x2 - x1, y2 - y1, x3 - x2, y3 - y2) >= 0)
            {
                fail = true;
                break;
            }
        }
        if (!fail)
            return true;
    }

    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        nerd.clear();
        normal.clear();
        for (int i = 0; i < n; i++)
        {
            int t, x, y;
            cin >> t >> x >> y;

            if (t) // 1 -> nerd
                nerd.push_back({x, y});
            else
                normal.push_back({x, y});
        }

        convexHull = makeConvexHull(nerd); // nerd convexHull
        convexHull2 = makeConvexHull(normal); // normal convexHull

        // for (int i = 0; i < convexHull.size(); i++)
        //     cout << convexHull[i].first << " " << convexHull[i].second << "\n";
        // cout << "\n\n";

        if (solve(convexHull, normal) || solve(convexHull2, nerd))
            cout << "THEORY HOLDS\n";
        else
            cout << "THEORY IS INVALID\n";
    }
}