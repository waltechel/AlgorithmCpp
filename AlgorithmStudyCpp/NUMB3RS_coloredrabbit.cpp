#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int MAX_N = 51, MAX_D = 101;
int main() {
	int T, n, d, p, e, i, j, t, q;
	double dp[MAX_D][MAX_N];
	vector<int> adj[MAX_N];
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &d, &p);
		for (i = 0; i < n; i++) {
			adj[i].clear();
			for (j = 0; j < n; j++) {
				scanf("%d", &e);
				if (e)
					adj[i].push_back(j);
			}
		}
		memset(dp, 0, sizeof dp);
		dp[0][p] = 1;
		for (i = 1; i <= d; i++) {
			for (j = 0; j < n; j++)
				for (int& v : adj[j])
					dp[i][j] += dp[i - 1][v] / adj[v].size();
		}
		scanf("%d", &t);
		while (t--) {
			scanf("%d", &q);
			printf("%.8lf ", dp[d][q]);
		}
		puts("");
	}
	return 0;
}