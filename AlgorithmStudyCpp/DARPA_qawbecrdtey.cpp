#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout.precision(2);
	cout << fixed;
	int t; cin >> t; while(t--) {
		int n, m; cin >> n >> m;
		auto a = new double[m];
		for(int i = 0; i < m; i++) cin >> a[i];
		double l = 0, r = a[m - 1] - a[0];
		double res = r;
		while(l + 1e-4 < r) {
			double const mid = (l + r) / 2;
			int cnt = 1, prev = 0;
			for(int i = 1; i < m; i++) {
				if(a[i] - a[prev] <= mid) continue;
				cnt++;
				prev = i;
			}
			if(cnt < n) {
				res = mid;
				r = mid;
			}
			else {
				l = mid;
			}
		}
		cout << res << '\n';
		delete[] a;
	}
}