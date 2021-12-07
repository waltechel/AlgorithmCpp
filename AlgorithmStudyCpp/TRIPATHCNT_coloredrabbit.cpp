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
	int T, i, j, N, A[MAX_N][MAX_N], dp[MAX_N][MAX_N] = {}, dp2[MAX_N][MAX_N] = {}, maxi;
	
	cin >> T;
	while (T--) {
		cin >> N;
		maxi = 0;
		for(i=1;i<=N;i++)
			for (j = 1; j <= i; j++) {
				cin >> A[i][j];
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + A[i][j];
				maxi = max(maxi, dp[i][j]);
			}

		memset(dp2, 0, sizeof dp2);
		for (i = 1; i <= N; i++)
			if (maxi == dp[N][i])
				dp2[N][i] = 1;

		for (i = N; i > 1; i--)
			for (j = 1; j <= i; j++) {
				if (dp[i - 1][j - 1] + A[i][j] == dp[i][j]) // left
					dp2[i - 1][j - 1] += dp2[i][j];

				if (dp[i - 1][j] + A[i][j] == dp[i][j]) // up
					dp2[i - 1][j] += dp2[i][j];
			}
		cout << dp2[1][1] << '\n';
	}
	return 0;
}