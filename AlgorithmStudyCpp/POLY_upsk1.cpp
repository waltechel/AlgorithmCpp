#include <bits/stdc++.h>
using namespace std;
long long d[101][101];
const long long mod = 10000000;
long long solve(int n, int first) {
	if (n == first)return 1;
	if (d[n][first] != -1)return d[n][first];
	d[n][first] = 0;
	for (int second = 1; second <= n - first; second++) {
		long long add = second + first - 1;
		add *= solve(n - first, second);
		add %= mod;
		d[n][first] += add;
		d[n][first] %= mod;
	}
	return d[n][first];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		memset(d, -1, sizeof(d));
		int n;
		cin >> n;
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += solve(n, i);
			ans %= mod;
		}
		cout << ans << '\n';

	}

}