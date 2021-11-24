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
const int MAX_N = 100, INF = 1e9, MAX_L = 100;
int dp[MAX_N][MAX_N], n, board[MAX_N][MAX_N];
int rec(int y, int x) {
	if (y == n) return 0;
	int& ret = dp[y][x];
	if (ret != -1) return ret;

	// get maximum value from sub-problems
	ret = max(rec(y + 1, x), rec(y + 1, x + 1)) + board[y][x];
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	int T, i, j;
	cin >> T;
	while (T--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) for (j = 0; j <= i; j++)
			scanf("%d", &board[i][j]);

		memset(dp, -1, sizeof dp);
		printf("%d\n", rec(0, 0));
	}
	return 0;
}