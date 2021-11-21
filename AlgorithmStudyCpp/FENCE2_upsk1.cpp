#include <bits/stdc++.h>
using namespace std;
int a[20001], n;
int solve(int l, int r) {
	if (l == r)return a[l];
	int mid = (l + r) / 2;
	int ret = max(solve(l, mid), solve(mid + 1, r));
	int lo = mid, hi = mid + 1;
	int h = min(a[lo], a[hi]);
	lo--; hi++;
	ret = max(ret, h * 2);
	while (l <= lo && hi <= r) {
		if (a[lo] > a[hi]) {
			h = min(h, a[lo]);
			ret = max(ret, h * (hi - lo));
			lo--;
		}
		else {
			h = min(h, a[hi]);
			ret = max(ret, h * (hi - lo));
			hi++;
		}

	}
	while (l <= lo) {
		h = min(h, a[lo]);
		ret = max(ret, h * (hi - lo));
		lo--;
	}
	while (hi <= r) {
		h = min(h, a[hi]);
		ret = max(ret, h * (hi - lo));
		hi++;
	}

	return ret;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++)cin >> a[i];
		cout << solve(0, n - 1) << '\n';
	}
}