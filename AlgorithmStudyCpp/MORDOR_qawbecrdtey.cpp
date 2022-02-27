#include <iostream>
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a > b ? b : a; }
void init(int *t, int const *a, int tidx, int l, int r, int(*f)(int, int)) {
	if(l == r) {
		t[tidx] = a[l];
		return;
	}
	auto const m = (l + r) >> 1;
	init(t, a, tidx << 1, l, m, f);
	init(t, a, (tidx << 1) | 1, m + 1, r, f);
	t[tidx] = f(t[tidx << 1], t[(tidx << 1) | 1]);
}
int get(int const *t, int const *a, int tidx, int start, int end, int l, int r, int(*f)(int, int)) {
	if(start <= l && r <= end) return t[tidx];
	if(r < start || end < l) return -1;
	auto const m = (l + r) >> 1;
	auto const x = get(t, a, tidx << 1, start, end, l, m, f);
	auto const y = get(t, a, (tidx << 1) | 1, start, end, m + 1, r, f);
	if(x == -1) return y;
	if(y == -1) return x;
	return f(x, y);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c; cin >> c; while(c--) {
		int n, q; cin >> n >> q;
		auto a = new int[n + 1];
		auto tmax = new int[n << 2];
		auto tmin = new int[n << 2];
		for(int i = 1; i <= n; i++) cin >> a[i];
		init(tmax, a, 1, 1, n, max);
		init(tmin, a, 1, 1, n, min);
		while(q--) {
			int x, y; cin >> x >> y; x++; y++;
			cout << get(tmax, a, 1, x, y, 1, n, max) - get(tmin, a, 1, x, y, 1, n, min) << '\n';
		}
		delete[] tmax;
		delete[] tmin;
		delete[] a;
	}
}