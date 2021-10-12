#include <bits/stdc++.h>
using namespace std;
struct A {
    int next, cost;
    bool operator<(const A& p)const {
        return cost > p.cost;
    }
};
vector<A> v[1001];
priority_queue<A> pq;
int d[1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n, m, fireCnt, manCnt;
        cin >> n >> m >> fireCnt >> manCnt;
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            d[i] = INT32_MAX;
        }
        for (int i = 0; i < m; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            v[x].push_back({ y,z });
            v[y].push_back({ x,z });
        }
        vector<int> fire(fireCnt), man(manCnt);
        for (int i = 0; i < fireCnt; i++)cin >> fire[i];
        for (int i = 0; i < manCnt; i++) {
            cin >> man[i];
            pq.push({ man[i],0 });
            d[man[i]] = 0;
        }
        while (!pq.empty()) {
            int now = pq.top().next;
            pq.pop();
            for (auto k : v[now]) {
                if (d[k.next] > d[now] + k.cost) {
                    d[k.next] = d[now] + k.cost;
                    pq.push({ k.next,d[k.next] });
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < fireCnt; i++)ans += d[fire[i]];
        cout << ans << '\n';
    }
}