#include <iostream>
using namespace std;
void init(int *t, int const *a, int tidx, int l, int r) {
	if(l == r) {
		t[tidx] = l;
		return;
	}
	auto const m = (l + r) / 2;
	init(t, a, tidx * 2, l, m);
	init(t, a, tidx * 2 + 1, m + 1, r);
	t[tidx] = (a[t[tidx * 2]] < a[t[tidx * 2 + 1]] ? t[tidx * 2] : t[tidx * 2 + 1]);
}
int mini(int const *t, int const *a, int tidx, int start, int end, int l, int r) {
	if(end < l || r < start) return 0;
	if(start <= l && r <= end) return t[tidx];
	auto const m = (l + r) / 2;
	auto const x = mini(t, a, tidx * 2, start, end, l, m);
	auto const y = mini(t, a, tidx * 2 + 1, start, end, m + 1, r);
	if(!x) return y;
	if(!y) return x;
	return a[x] < a[y] ? x : y;
}
int res(int const *t, int const *a, int n, int l, int r) {
	if(l > r) return 0;
	auto const m = mini(t, a, 1, l, r, 1, n);
	auto const left = res(t, a, n, l, m - 1);
	auto const right = res(t, a, n, m + 1, r);
	int res = a[m] * (r - l + 1);
	if(res < left) res = left;
	if(res < right) res = right;
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c; cin >> c;
	while(c--) {
		int n; cin >> n;
		auto a = new int[n + 1];
		auto t = new int[n * 4];
		for(int i = 1; i <= n; i++) cin >> a[i];
		init(t, a, 1, 1, n);
		cout << res(t, a, n, 1, n) << '\n';
		delete[] a;
		delete[] t;
	}
}