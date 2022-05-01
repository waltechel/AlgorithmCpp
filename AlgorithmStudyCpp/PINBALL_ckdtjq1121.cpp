// OMG 핀볼의 크기가 반지름이 1인 원이다. => 장애물의 반지름이 1 커지는것과 동일 하다.

// x, y, dx, dy 의 의미 : (x,y) 에서 시작하는 y = dy/dx(x - x1) + y1 직선의 방정식
// 가장 먼저 충돌하는 지점 찾기
// 충돌하는 모든 장애물 중 거리가 가장 짧은 것 선택하기( 단, dx, dy 방향의 장애물 중)

// 충돌 지점(cx, cy)과 튕겨나가는 ndx, ndy 기울기 찾기
// 충돌 지점의 접선에서의 입사각과 반사각이 같다.
// 벡터 회전을 이용 하기

// 100번 부딪힐때 까지 또는 밖으로 나갈떄
// 밖으로 나가는 것은 충돌하는 장애물이 없다.

#include <bits/stdc++.h>

using namespace std;

struct circle
{
    double y;
    double x;
    double r;
};
int n;
vector<circle> arr;
vector<int> ans;

// y = dy/dx (x - x1) + y1;
// dyx -dxy -dyx1 +dxy1 = 0;
double distance(double x1, double y1, double dx, double dy, int i)
{
    // ax + by + c = 0;
    double a = dy;
    double b = -dx;
    double c = -dy * x1 + dx * y1;

    double dist = abs(a * arr[i].x + b * arr[i].y + c) / sqrt(a * a + b * b);
    return dist;
}

// 기울기를 크기가 1인 벡터로 일반화
pair<double, double> normalizeVector(double dx, double dy)
{
    double size = sqrt(dx * dx + dy * dy);
    return {dx / size, dy / size};
}

pair<double, double> conflictPoint(double x1, double y1, double dx, double dy, double rx, double ry, double rr, double dist)
{
    // 교점 X (원의 중심과 직선이 수직으로 만나는 지점)
    // 원의 중심점 R
    // 충돌점 C

    double xx, xy;
    if (-1e-7 < dx && dx < 1e-7)
    {
        xx = x1;
        xy = ry;
    }
    else if (-1e-7 < dy && dy < 1e-7)
    {
        xx = rx;
        xy = y1;
    }
    else
    {
        xx = ((y1 - x1 * dy / dx) - (ry + rx * dx / dy)) / (-dx / dy - dy / dx);
        xy = (-dx / dy * xx + (ry + rx * dx / dy));
    }

    pair<double, double> normalV = normalizeVector(dx, dy);
    double L = sqrt(rr * rr - dist * dist); // 충돌점 -> 교점 까지의 거리
    double cx = xx - L * normalV.first;     // Xx에서 L길이만큼 뺀위치
    double cy = xy - L * normalV.second;    // xy에서 L길이 만큼 뺀위치
    return {cx, cy};
}
// (ax, bx) 벡터에서 ccw로 (cin x, sin x) x각도 만큼 회전시킨다.
pair<double, double> rotate(double cx, double sx, double ax, double bx)
{
    return {cx * ax - sx * bx, sx * ax + cx * bx};
}
pair<double, double> reflectVector(double dx, double dy, double mx, double my)
{
    // 장애물의 접선의 벡터 방향 맞추기
    if (dx * mx + dy * my < 1e-7)
        mx *= -1, my *= -1;

    pair<double, double> tmp = rotate(mx, -my, dx, dy); // d - m == tmp (사잇각)
    pair<double, double> ret = rotate(tmp.first, -tmp.second, mx, my); // m - tmp == ret (반사각)
    return ret;
}
void conflictObstacle(double x1, double y1, double dx, double dy, int prev)
{
    // 100번만 충돌
    if (ans.size() == 100)
        return;

    double shortestDist = DBL_MAX;
    int idx = -1;
    double cx, cy; // 충돌하는 좌표
    for (int i = 0; i < n; i++)
    {
        if (i == prev) // prev원의 위에서 출발하기 떄문에 바로 부딪히지 않게 하기 위함
            continue;

        double dist = distance(x1, y1, dx, dy, i); // i번째 원과 직선의 거리
        if (arr[i].r - dist >= 1e-7)               // 충돌
        {
            pair<double, double> cand = conflictPoint(x1, y1, dx, dy, arr[i].x, arr[i].y, arr[i].r, dist);
            // dx dy 의 방향과 같은 방향에서의 충돌만 인정
            if ((cand.first - x1) * dx + (cand.second - y1) * dy >= 1e-7)
            {
                double tmp_dist = (cand.first - x1) * (cand.first - x1) + (cand.second - y1) * (cand.second - y1);
                if (tmp_dist < shortestDist)
                {
                    shortestDist = tmp_dist;
                    idx = i;
                    cx = cand.first;
                    cy = cand.second;
                }
            }
        }
    }

    // a * b = -1 // a기울기와 b기울기의 직선은 직교한다.
    // 접선의 기울기 = -(arr[idx].x - cx) / (arr[idx].y - cy) == my / mx
    if (idx != -1) // 충돌이 일어났다.
    {
        ans.push_back(idx);

        double mx = (arr[idx].y - cy);
        double my = -(arr[idx].x - cx);
        pair<double, double> normalV = normalizeVector(dx, dy);
        pair<double, double> normalMV = normalizeVector(mx, my);
        pair<double, double> reflectV = reflectVector(normalV.first, normalV.second, normalMV.first, normalMV.second);

        conflictObstacle(cx, cy, reflectV.first, reflectV.second, idx);
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
        double x, y, dx, dy;
        cin >> x >> y >> dx >> dy >> n;

        arr = vector<circle>(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].x >> arr[i].y >> arr[i].r;
            arr[i].r++; // 핀볼의 크기 1
        }

        conflictObstacle(x, y, dx, dy, -1);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << "\n";

        ans.clear();
    }
}