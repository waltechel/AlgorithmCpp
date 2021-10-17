#include <bits/stdc++.h>
using namespace std;
int V, adj[500][500];
int delay[500];
int W[500][500];
const int INF = 10000000;
void solve() {
    vector<pair<int, int>> order;
    for (int i = 0; i < V; i++)order.push_back({ delay[i],i });
    sort(order.begin(), order.end());
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j)W[i][j] = 0;
            else W[i][j] = adj[i][j];
        }
    }
    for (int k = 0; k < V; k++) {
        int w = order[k].second;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
                W[i][j] = min(W[i][j], adj[i][w] + adj[w][j] + delay[w]);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m;
    cin >> V >> m;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                adj[i][j] = 0;
                continue;
            }
            adj[i][j] = INF;
        }
    }

    for (int i = 0; i < V; i++)cin >> delay[i];
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        adj[x][y] = adj[y][x] = z;
    }
    solve();
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << W[x][y] << '\n';
    }
}