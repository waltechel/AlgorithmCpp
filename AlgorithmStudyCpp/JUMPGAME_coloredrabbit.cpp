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
using ll = long long;
using namespace std;
const int MAX_N = 100, INF = 1e9, SWITCH = 10, SZ = 60, BASE=1e9;
int dp[MAX_N][MAX_N], board[MAX_N][MAX_N], n;
int rec(int r, int c) {
	if (r == n - 1 && c == n - 1) return 1;
	if (r >= n || c >= n) return 0; // out of bound
	int& ret = dp[r][c];
	if (ret != -1) return ret;

	// right or down
	ret = rec(r + board[r][c], c) || rec(r, c + board[r][c]);
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	int T, i, j;
	scanf("%d\n", &T); 
	while (T--) {
		scanf("%d", &n);
		memset(dp, -1, sizeof dp);
		for (i = 0; i < n; i++) for (j = 0; j < n; j++)
			scanf("%d", &board[i][j]);
		puts(rec(0, 0) ? "YES" : "NO");
	}
	return 0;
}