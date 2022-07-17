#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
using point = pair<ll, ll>;
struct line { point a, b; };
inline ll ccw(point a, point b, point c) {
	ll const v = a.first * b.second + b.first * c.second + c.first * a.second - a.second * b.first - b.second * c.first - c.second * a.first;
	if(!v) return 0;
	if(v > 0) return 1;
	return -1;
}
inline bool intersect(line l, line m) {
	ll const ab = ccw(l.a, l.b, m.a) * ccw(l.a, l.b, m.b);
	ll const cd = ccw(m.a, m.b, l.a) * ccw(m.a, m.b, l.b);
	if(!ab && !cd) {
		if(l.a > l.b) swap(l.a, l.b);
		if(m.a > m.b) swap(m.a, m.b);
		return m.a <= l.b && l.a <= m.b;
	} return ab <= 0 && cd <= 0;
}
struct uf {
	int *root;
	uf(int n) : root(new int[n]) { for(int i = 0; i < n; i++) root[i] = i; }
	int find(int a) {
		if(a == root[a]) return a;
		return root[a] = find(root[a]);
	}
	bool merge(int a, int b) {
		int x = find(a);
		int y = find(b);
		if(x == y) return false;
		root[x] = y;
		return true;
	}
	bool check(int a, int b) { return find(a) == find(b); }
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto a = new line[n];
	uf u(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i].a.first >> a[i].a.second >> a[i].b.first >> a[i].b.second;
		for(int j = 0; j < i; j++) {
			if(intersect(a[i], a[j])) {
				u.merge(i, j);
			}
		}
	}
	auto res = new int[n]();
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		res[u.find(i)]++;
		cnt += (u.find(i) == i);
	}
	cout << cnt << '\n';
	int m = 0;
	for(int i = 0; i < n; i++) {
		if(m < res[i]) m = res[i];
	} cout << m;
}