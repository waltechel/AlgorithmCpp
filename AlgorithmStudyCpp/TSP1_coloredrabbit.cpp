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
using ll = long long;
using namespace std;
const int MAX_N = 8, INF = 1e9;
int main() {
	freopen("input.txt", "r", stdin);
	int T, N, i, j, k, L;
	double adj[MAX_N][MAX_N], dp[1 << MAX_N][MAX_N] = {}, ans;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (i = 0; i < N; i++) for (j = 0; j < N; j++)
			scanf("%lf", &adj[i][j]);

		L = 1 << N;
		for (i = 1; i < L; i++) { // i : status
			for (j = 0; j < N; j++) { // if j-th city visited, set j-th last visited city.
				dp[i][j] = INF;
				if (i & (1 << j)) {
					for (k = 0; k < N; k++) // k : find a city where visited before j-th city
						if (j != k && (i & (1 << k)))
							dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + adj[k][j]);
				}
				if (dp[i][j] == INF) // if starting point
					dp[i][j] = 0;
			}
		}
		ans = INF;
		for (i = 0; i < N; i++)
			ans = min(ans, dp[L - 1][i]);
		printf("%.10lf\n", ans);
	}
	return 0;
}