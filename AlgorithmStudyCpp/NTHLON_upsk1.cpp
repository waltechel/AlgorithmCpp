#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v[402];
int start = 401;
int dist[402];
const int INF = 10000000;
struct A {
    int cost, vertex;
    bool operator<(const A& p)const {
        return cost > p.cost;
    }
};
priority_queue<A> pq;
int dijkstra() {
    for (int i = 0; i < 402; i++)dist[i] = INF;
    dist[start] = 0;
    pq.push({ 0,start });
    while (!pq.empty()) {
        int cost = pq.top().cost;
        int here = pq.top().vertex;
        pq.pop();
        if (dist[here] < cost)continue;
        for (auto i : v[here]) {
            if (dist[i.second] > dist[here] + i.first) {
                dist[i.second] = dist[here] + i.first;
                pq.push({ dist[i.second],i.second });
            }
        }
    }
    return dist[200];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 402; i++)v[i].clear();
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            int dif = x - y;
            v[start].push_back({ x,200 + dif });
            for (int j = -200; j < 200; j++) {
                int next = j + dif;
                if (next > -200 && next < 200)v[j + 200].push_back({ x,next + 200 });
            }
        }
        int ans = dijkstra();
        if (ans == INF)cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
    }
}