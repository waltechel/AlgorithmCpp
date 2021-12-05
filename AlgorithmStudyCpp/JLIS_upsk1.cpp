#include <bits/stdc++.h>
using namespace std;

long long a[101], b[101];
int d[101][101];
int n, m;
int solve(int l, int r) {
	if (d[l][r] != -1)return d[l][r];
	d[l][r] = 0;
	long long MAX = max(a[l], b[r]);
	for (int i = l + 1; i <= n; i++) {
		if (MAX < a[i]) {
			d[l][r] = max(d[l][r], solve(i, r) + 1);
		}
	}
	for (int i = r + 1; i <= m; i++) {
		if (MAX < b[i]) {
			d[l][r] = max(d[l][r], solve(l, i) + 1);
		}
	}
	return d[l][r];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	a[0] = b[0] = INT64_MIN;
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= m; i++) {
			cin >> b[i];
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				d[i][j] = -1;
			}
		}
		cout << solve(0, 0) << '\n';
	}
}