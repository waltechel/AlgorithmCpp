#include <bits/stdc++.h>
using namespace std;
int p[101];
int cnt[101];
int Find(int x) {
	if (x == p[x])return x;
	else return p[x] = Find(p[x]);
}
void Union(int x, int y) {
	x = Find(x); y = Find(y);
	if (x == y)return;
	p[y] = x;
	cnt[x] += cnt[y];
}
pair<double, double> pos[101];
double d[101][101];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision(2);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> pos[i].first >> pos[i].second;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				d[i][j] = sqrt((pos[i].first - pos[j].first) * (pos[i].first - pos[j].first) +
					(pos[i].second - pos[j].second) * (pos[i].second - pos[j].second));
			}
		}
		double l = 0, r = 2000;
		for (int i = 0; i < 100; i++) {
			double mid = (l + r) / 2.0;
			for (int j = 1; j <= n; j++) {
				p[j] = j;
				cnt[j] = 1;
			}
			for (int j = 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					if (d[j][k] <= mid) {
						Union(j, k);
					}
				}
			}
			if (cnt[Find(1)] == n)r = mid;
			else l = mid;
		}
		cout << l << '\n';
	}


}