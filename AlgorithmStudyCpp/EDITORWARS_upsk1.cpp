#include <bits/stdc++.h>
using namespace std;
int p[10001],cnt[10001],enemy[10001];
bool check[10001];
int Find(int x) {
	if (x == p[x])return x;
	else return p[x] = Find(p[x]);
}
int Union(int x, int y) {
	if (x == -1 || y == -1)return max(x, y);
	x = Find(x);
	y = Find(y);
	if (x == y)return x;
	p[y] = x;
	cnt[x] += cnt[y];
	return x;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m,ans=0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			enemy[i] = -1;
			p[i] = i;
			cnt[i] = 1;
			check[i] = false;
		}
		int contradiction = -1;
		for (int i = 1; i <= m; i++) {
			string type; int x, y;
			cin >> type >> x >> y;
			if (contradiction != -1)continue;
			x = Find(x); y = Find(y);

			if (type[0] == 'A') {
				if (enemy[x] == y) {
					contradiction = i;
					continue;
				}
				int a=Union(x, y),b=Union(enemy[x],enemy[y]);
				enemy[a] = b;
				if (b != -1) enemy[b] = a;
			}
			else {
				if (x == y) {
					contradiction = i;
					continue;
				}
				int a = Union(x, enemy[y]), b = Union(enemy[x], y);
				enemy[a] = b; enemy[b] = a;
			}
		}
		if (contradiction == -1) {
			for (int i = 0; i < n; i++) {
				if (check[Find(i)])continue;
				int myCnt = cnt[Find(i)], enemyCnt = 0;
				check[Find(i)] = true;
				if (enemy[Find(i)] != -1) {
					check[enemy[Find(i)]] = true;
					enemyCnt = cnt[enemy[Find(i)]];
				}
				ans += max(myCnt, enemyCnt);
			}
			cout << "MAX PARTY SIZE IS " << ans << '\n';
		}
		else cout << "CONTRADICTION AT "<<contradiction << '\n';
	}
}