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
const int MAX_N = 1e3+1, MAX_L = 100, INF = 1e9, RANGE = 1e3+1, MOD = 1e9+7;
double dp[MAX_N][MAX_N];
double rec(int n, int m) {
	if (n <= 0) return 1;
	if (m == 0) return 0;
	double& ret = dp[n][m];
	if (ret != -1) return ret;
	ret = rec(n-2,m-1)*0.75 + rec(n-1,m-1)*0.25;
	return ret;
}
int main() {
	int T, N, M, i, j;
	for (i = 0; i < MAX_N; i++)
		for (j = 0; j < MAX_N; j++)
			dp[i][j] = -1;

	cout.precision(10);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		cout << fixed << rec(N, M) << '\n';
	}
	return 0;
}