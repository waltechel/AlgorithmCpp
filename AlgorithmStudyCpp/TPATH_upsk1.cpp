#include <bits/stdc++.h>
using namespace std;
int p[2001];
int Find(int x) {
	if (x == p[x])return x;
	else return p[x] = Find(p[x]);
}
void Union(int x, int y) {
	x = Find(x); y = Find(y);
	p[y] = x;
}
struct A {
	int x, y, z;
	bool operator<(const A& P)const {
		return z < P.z;
	}
};
A a[4001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++)cin >> a[i].x >> a[i].y >> a[i].z;
		if (n == 1) {
			cout << 0 << '\n';
			continue;
		}
		sort(a, a + m);
		int n2 = n - 1, ans = 1000;
		for (int low = 0; low < 1001; low++) {
			for (int i = 0; i < n; i++)p[i] = i;
			for (int i = 0; i < m; i++) {
				if (a[i].z < low)continue;
				Union(a[i].x, a[i].y);
				if (Find(0) == Find(n2)) {
					ans = min(ans, a[i].z - low);
					break;
				}
			}
		}
		cout << ans << '\n';
	}
}