#include <bits/stdc++.h>
using namespace std;
vector<int> v[100002];
bool visited[100002];
queue<int> q;
int p[100002][18], depth[100002], dist[100002];
pair<int, int> lca(int x, int y) {
	int ret = 0;
	if (depth[x] < depth[y])swap(x, y);
	int l = 1;
	for (l = 1; (1 << l) <= depth[x]; l++);
	l--;
	for (int i = l; i >= 0; i--) {
		if (depth[x] - (1 << i) >= depth[y]) {
			x = p[x][i];
			ret += (1 << i);
		}
	}
	if (x == y)return { x,ret };
	for (int i = l; i >= 0; i--) {
		if (p[x][i]) {
			if (p[x][i] != p[y][i]) {
				x = p[x][i];
				y = p[y][i];
				ret += (1 << i) * 2;
			}
		}
	}
	return { p[x][0],ret + 2 };
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			v[i].clear();
			visited[i] = false;
			depth[i] = dist[i] = 0;
		}
		for (int i = 2; i <= n; i++) {
			cin >> p[i][0];
			p[i][0]++;
			v[i].push_back(p[i][0]);
			v[p[i][0]].push_back(i);
		}
		q.push(1);
		visited[1] = true;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (auto k : v[x]) {
				if (visited[k] == false) {
					visited[k] = true;
					depth[k] = depth[x] + 1;
					dist[k] = dist[x] + 1;
					q.push(k);
				}
			}
		}
		for (int j = 1; (1 << j) < n; j++) {
			for (int i = 1; i <= n; i++) {
				if (p[i][j - 1]) {
					p[i][j] = p[p[i][j - 1]][j - 1];
				}
			}
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x++; y++;
			pair<int, int> lcaXY = lca(x, y);
			cout << lcaXY.second << '\n';
		}
		for (int j = 1; (1 << j) < n; j++) {
			for (int i = 1; i <= n; i++) {
				p[i][j] = 0;
			}
		}
	}
}