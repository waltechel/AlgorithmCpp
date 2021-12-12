#include <algorithm>
#include <iostream>
using ll = long long;
inline ll mod(ll n, ll m) { if(m < 0) m = -m; return (n % m + m) % m; }
inline ll quot(ll n, ll m) { return (n - mod(n, m)) / m; }
inline ll calc(ll two, ll one, ll n) {
	ll m = quot(one, n);
	ll val1 = two - 2 * one * m + n * m * m;
	ll val2 = two - 2 * one * (m + 1) + n * (m + 1) * (m + 1);
	return std::min(val1, val2);
}
ll f(ll *const *const dp, ll const *const *const var, int n, int idx, int s) {
	if(dp[idx][s] != -1) return dp[idx][s];
	if(n == idx) return 0;
	ll res = var[idx][n - 1];
	if(s == 1) return res;
	for(int i = idx; i < n - 1; i++) {
		ll const val = var[idx][i] + f(dp, var, n, i + 1, s - 1);
		if(res > val) res = val;
	}
	return dp[idx][s] = res;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while(t--) {
		int n, s;
		std::cin >> n >> s;
		auto in = new ll[n];
		for(int i = 0; i < n; i++) std::cin >> in[i];
		std::sort(in, in + n);
		auto a = new ll[n + 1]; a[0] = 0;
		auto a2 = new ll[n + 1]; a2[0] = 0;
		for(int i = 1; i <= n; i++) {
			ll const x = in[i - 1];
			a[i] = x + a[i - 1];
			a2[i] = x * x + a2[i - 1];
		}
		auto var = new ll*[n];
		auto dp = new ll*[n];
		for(int i = 0; i < n; i++) {
			var[i] = new ll[n];
			dp[i] = new ll[s + 1];
			std::fill(dp[i], dp[i] + s + 1, -1);
			for(int j = i; j < n; j++) {
				var[i][j] = calc(a2[j + 1] - a2[i], a[j + 1] - a[i], j - i + 1);
			}
		}
		std::cout << f(dp, var, n, 0, s) << '\n';
		for(int i = 0; i < n; i++) delete[] var[i];
		delete[] var;
		delete[] a2;
		delete[] a;
		delete[] in;
	}
}