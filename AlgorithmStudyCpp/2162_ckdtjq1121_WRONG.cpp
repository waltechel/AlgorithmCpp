#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<pair<pair<int, int>, pair<int, int>>> a;

int find(int u)
{
    if (u == parent[u])
        return u;

    return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
    u = find(u), v = find(v);

    if (u != v)
        parent[u] = v;
}

pair<double, double> normalizeVector(double dx, double dy)
{
    double size = sqrt(dx * dx + dy * dy);
    return {dx / size, dy / size};
}
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

bool conflict(int u, int v) // u,v line
{
    bool isZero = false;
    int l = ccw(a[u].second.first - a[u].first.first, a[u].second.second - a[u].first.second, a[v].first.first - a[u].second.first, a[v].first.second - a[u].second.second);
    int r = ccw(a[u].second.first - a[u].first.first, a[u].second.second - a[u].first.second, a[v].second.first - a[u].second.first, a[v].second.second - a[u].second.second);

    if (l == 0 && r == 0)
        isZero = true;
    if (l * r > 0)
        return false;

    l = ccw(a[v].second.first - a[v].first.first, a[v].second.second - a[v].first.second, a[u].first.first - a[v].second.first, a[u].first.second - a[v].second.second);
    r = ccw(a[v].second.first - a[v].first.first, a[v].second.second - a[v].first.second, a[u].second.first - a[v].second.first, a[u].second.second - a[v].second.second);
    if (l * r > 0)
        return false;

     if (l == 0 && r == 0)
        isZero = true;

    if (isZero)
    {
        int x1 = a[u].first.first;
        int x2 = a[u].second.first;
        int x3 = a[v].first.first;
        int x4 = a[v].second.first;

        if (x1 > x2)
            swap(x1, x2);

        if (x3 > x4)
            swap(x3, x4);

        if ((x1 <= x3 && x3 <= x2) || (x1 <= x4 && x4 <= x2) || (x3 <= x1 && x1 <= x4) || (x3 <= x2 && x2 <= x4))
            return true;
        else
            return false;
    }
    else
        return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    a = vector<pair<pair<int, int>, pair<int, int>>>(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first.first >> a[i].first.second >> a[i].second.first >> a[i].second.second;

    parent = vector<int>(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (find(i) == find(j))
                continue;

            if (conflict(i, j))
                merge(i, j);
        }
    }

    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++)
    {
        cnt[find(i)]++;
    }
    int num = 0, maxSize = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt[i])
        {
            num++;
            maxSize = max(maxSize, cnt[i]);
        }
    }

    cout << num << "\n";
    cout << maxSize << "\n";
}