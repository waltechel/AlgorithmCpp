#include <bits/stdc++.h>
using namespace std;
vector<int> v[1001];
bool visited[1001];
int ans = 0;
int dfs(int x) {
	visited[x] = true;
	int children[3] = { 0,0,0 };
	for (auto k : v[x]) {
		if (visited[k] == false) {
			children[dfs(k)]++;
		}
	}
	if (children[0]) {
		ans++;
		return 2;
	}
	if (children[2]) {
		return 1;
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		ans = 0;
		for (int i = 0; i < n; i++) {
			v[i].clear();
			visited[i] = false;
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for (int i = 0; i < n; i++) {
			if (visited[i] == false) {
				if (dfs(i) == 0)ans++;
			}
		}
		cout << ans << '\n';
	}
}