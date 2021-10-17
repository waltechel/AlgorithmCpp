#include <bits/stdc++.h>
using namespace std;
int V, V2;
const int INF = 10000000;
vector<pair<int, int>> adj[101];
pair<int, int> bellman2(int src, int target) {
    vector<int> Upper(V, INF);
    vector<int> Lower(V, INF);
    Upper[src] = 0; Lower[src] = 0;
    bool Uflag = false, Lflag = false;
    for (int iter = 1; iter <= V2; iter++) {
        for (int here = 0; here < V; here++) {
            for (int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                if (Upper[here] != INF) {
                    if (Upper[there] > Upper[here] + cost) {
                        Upper[there] = Upper[here] + cost;
                        if (iter >= V && there == 1) {
                            Uflag = true;
                        }
                    }
                }
                if (Lower[here] != INF) {
                    if (Lower[there] > Lower[here] - cost) {
                        Lower[there] = Lower[here] - cost;
                        if (iter >= V && there == 1) {
                            Lflag = true;
                        }
                    }
                }
            }
        }
    }
    pair<int, int> ret = { Upper[1],-Lower[1] };
    if (Uflag)ret.first = INF + 1;
    if (Lflag)ret.second = INF + 1;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int m;
        cin >> V >> m;
        V2 = V * 2;
        for (int i = 0; i < V; i++)adj[i].clear();
        for (int i = 0; i < m; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            adj[x].push_back({ y,z });
        }
        auto ans = bellman2(0, 1);
        if (ans.first == INF) {
            cout << "UNREACHABLE\n";
        }
        else {
            if (ans.first > INF)cout << "INFINITY ";
            else cout << ans.first << ' ';
            if (ans.second > INF)cout << "INFINITY\n";
            else cout << ans.second << '\n';
        }
    }

}