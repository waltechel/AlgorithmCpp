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
const int MAX_N = 1e2+1, MAX_L = 100, INF = 1e9, RANGE = 1e3+1, MOD = 1e9 + 7;
int main() {
	int T, i, S, N, dp[MAX_N] = { 1,1 };
	for (i = 2; i < MAX_N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	cin >> T;
	while (T--) {
		cin >> N;
		cout << dp[N] << '\n';
	}
	return 0;
}