#include <bits/stdc++.h>
using namespace std;
pair<double, double> p[501];
struct A {
	int x, y;
	double d;
	bool operator<(const A& P)const {
		return d < P.d;
	}
};
double dist(pair<double, double> p1, pair<double, double> p2) {
	return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}
double adj[501][501];
A a[250001];
int parent[501];
int Find(int x) {
	if (x == parent[x])return x;
	else return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	x = Find(x); y = Find(y);
	parent[y] = x;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision(10);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)parent[i] = i;
		for (int i = 0; i < n; i++)cin >> p[i].first;
		for (int i = 0; i < n; i++)cin >> p[i].second;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				adj[i][j] = dist(p[i], p[j]);
				adj[j][i] = adj[i][j];
			}
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x][y] = adj[y][x] = 0;
		}
		int idx = 0;
		double ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				a[idx].x = i; a[idx].y = j; a[idx].d = adj[i][j];
				idx++;
			}
		}
		sort(a, a + idx);
		for (int i = 0; i < idx; i++) {
			if (Find(a[i].x) != Find(a[i].y)) {
				Union(a[i].x, a[i].y);
				ans += a[i].d;
			}
		}
		cout << ans << '\n';
	}
}