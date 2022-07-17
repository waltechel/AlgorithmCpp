#include <bits/stdc++.h>
using namespace std;
double a[201];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision(2);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a[i];
		}
		double l = 0, r = 240;
		for (int i = 0; i < 100; i++) {
			double mid = (l + r) / 2.0;
			int cnt = 0;
			double start = -300;
			for (int j = 0; j < m; j++) {
				if (a[j] - start >= mid) {
					cnt++;
					start = a[j];
				}
			}
			if (cnt < n)r = mid;
			else l = mid;
		}
		cout << l << '\n';

	}


}