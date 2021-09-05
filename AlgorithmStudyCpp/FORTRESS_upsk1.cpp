#include <bits/stdc++.h>
using namespace std;
int n, d[101];
bool visited[101];
vector<int> v[101];
struct A {
	int x, y, r;
};
A a[101];
int sqr(int x) { return x * x; }
int dist(int c1, int c2) { return sqr(a[c1].x - a[c2].x) + sqr(a[c1].y - a[c2].y); }
bool encloses(int c1, int c2) { return a[c1].r > a[c2].r && dist(c1, c2) < sqr(a[c1].r - a[c2].r); }
bool isChild(int c1, int c2) {
	if (encloses(c1, c2) == false)return false;
	for (int i = 0; i < n; i++) {
		if (i == c1 || i == c2)continue;
		if (encloses(c1, i) && encloses(i, c2))return false;
	}
	return true;
}
void dfs(int x, int distance) {
	visited[x] = true;
	d[x] = distance;
	for (auto k : v[x]) {
		if (visited[k] == false) {
			dfs(k, distance + 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].r;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)continue;
				if (isChild(i, j)) {
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		dfs(0, 0);
		int start = 0, MAX = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			if (MAX < d[i]) {
				MAX = d[i];
				start = i;
			}
			d[i] = 0;
			visited[i] = false;
		}
		dfs(start, 0);
		for (int i = 0; i < n; i++) {
			ans = max(ans, d[i]);
			d[i] = 0;
			visited[i] = false;
			v[i].clear();
		}
		cout << ans << '\n';
	}



}