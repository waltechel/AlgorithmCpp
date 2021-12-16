#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<string>
using ll = long long;
using namespace std;
const int MAX_N = 1e2+1, MAX_L = 100, INF = 1e9, RANGE = 1e3+1, MOD = 1e7;
int dp[MAX_N][MAX_N];
int rec(int b, int n) {
	if (n == 0) return 1;
	int& ret = dp[b][n];
	if (ret != -1) return ret;
	ret = 0;
	int i;
	if (b == 0) {
		for (i = 1; i <= n; i++)
			ret = (ret + rec(i, n - i)) % MOD;
	}
	else {
		for (i = 1; i <= n; i++)
			ret = (ret + rec(i, n - i) * (b + i - 1LL) % MOD) % MOD;
	}
	return ret;
}
int main() {
	int T, N, i;
	memset(dp, -1, sizeof dp);
	cin >> T;
	while (T--) {
		cin >> N;
		cout << rec(0, N) << '\n';
	}
	return 0;
}