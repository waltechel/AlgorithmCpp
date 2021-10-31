#include <bits/stdc++.h>
using namespace std;
int V, adj[201][201];
const int INF = 10000000;
bool update(int a, int b, int c) {
	if (adj[a][b] <= c)return false;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			adj[i][j] = min({ adj[i][j],adj[i][a] + adj[b][j] + c,adj[i][b] + adj[a][j] + c });
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int m, n;
		cin >> V >> m >> n;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (i == j)adj[i][j] = 0;
				else adj[i][j] = INF;
			}
		}
		for (int i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			adj[x][y] = min(adj[x][y], z);
			adj[y][x] = min(adj[y][x], z);
		}
		for (int k = 0; k < V; k++) {
			for (int i = 0; i < V; i++) {
				for (int j = 0; j < V; j++) {
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			if (update(a, b, c) == false)ans++;
		}
		cout << ans << '\n';
	}
}