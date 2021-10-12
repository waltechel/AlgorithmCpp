#include <bits/stdc++.h>
using namespace std;
struct A {
    int next;
    double cost;
    bool operator<(const A& p)const {
        return cost > p.cost;
    }
};
vector<A> v[10001];
priority_queue<A> pq;
int n, m;
double d[10001];
bool check[10001];
double dijkstra() {
    for (int i = 0; i < n; i++) {
        d[i] = DBL_MAX;
        check[i] = false;
    }
    d[0] = 1;
    pq.push({ 0,1 });
    while (!pq.empty()) {
        int now = pq.top().next;
        pq.pop();
        if (check[now])continue;
        check[now] = true;
        for (auto k : v[now]) {
            if (d[k.next] > d[now] * k.cost) {
                d[k.next] = d[now] * k.cost;
                pq.push({ k.next,d[k.next] });
            }
        }
    }
    return d[n - 1];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed;
    cout.precision(10);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)v[i].clear();
        for (int i = 0; i < m; i++) {
            int x, y;
            double cost;
            cin >> x >> y >> cost;
            v[x].push_back({ y,cost });
            v[y].push_back({ x,cost });
        }
        cout << dijkstra() << '\n';
    }
}