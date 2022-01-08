#include <bits/stdc++.h>
using namespace std;
int n, m;
double d[1001][2001];
double solve(int days, int climbed) {
	if (days == m) return climbed >= n ? 1 : 0;
	if (d[days][climbed] != -1.0)return d[days][climbed];
	return d[days][climbed] = 0.75 * solve(days + 1, climbed + 2) + 0.25 * solve(days + 1, climbed + 1);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision(10);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		int m2 = m * 2;
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= m2; j++)d[i][j] = -1;
		}
		cout << solve(0, 0) << '\n';
	}
}