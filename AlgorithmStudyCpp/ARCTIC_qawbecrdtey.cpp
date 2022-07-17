#include <cmath>
#include <iostream>
using namespace std;
struct point { double x, y; };
inline double dist2(point const &a, point const &b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
struct uf {
	int *root;
	uf(int n) : root(new int[n]) {
		for(int i = 0; i < n; i++) root[i] = i;
	}
	~uf() { delete[] root; }
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
	bool check(int a, int b) {
		return find(a) == find(b);
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout.precision(2); cout << fixed;
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		auto a = new point[n];
		double l = 0, r = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i].x >> a[i].y;
			for(int j = 0; j < i; j++) {
				double const d = dist2(a[i], a[j]);
				if(d > r) r = d;
			}
		}
		double res = r;
	LP:	while(l + 1e-4 < r) {
			double const m = (l + r) / 2;
			uf u(n);
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < i; j++) {
					double const d = dist2(a[i], a[j]);
					if(d <= m) u.merge(i, j);
				}
			}
			for(int i = 1; i < n; i++) {
				if(!u.check(0, i)) {
					l = m;
					goto LP;
				}
			}
			res = r;
			r = m;
		}
		cout << sqrt(res) << '\n';
		delete[] a;
	}
}