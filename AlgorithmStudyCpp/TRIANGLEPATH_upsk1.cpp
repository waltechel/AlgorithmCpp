#include <bits/stdc++.h>
using namespace std;
int a[101][101], d[101][101];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				cin >> a[i][j];
				d[i][j] = a[i][j];
				ans = max(ans, d[i][j]);
			}
		}
		for (int i = 2; i <= n; i++) {
			d[i][1] = d[i - 1][1] + a[i][1];
			ans = max(ans, d[i][1]);
			for (int j = 2; j < i; j++) {
				d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + a[i][j];
				ans = max(ans, d[i][j]);
			}
			d[i][i] = d[i - 1][i - 1] + a[i][i];
			ans = max(ans, d[i][i]);
		}
		cout << ans << '\n';
	}
}