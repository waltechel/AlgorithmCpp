#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX_N = 501;
int main() {
	int N, M, A[MAX_N], B[MAX_N], i, j, k, dp[MAX_N][MAX_N], ans = 0, sz;
	pair<int, int> from[MAX_N][MAX_N], _first, _cur;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &A[i]);
	scanf("%d", &M);
	for (i = 0; i < M; i++) scanf("%d", &B[i]);

	memset(dp, 0, sizeof dp);
	memset(from, -1, sizeof from);
	for (i = N - 1; i >= 0; i--)
		for (j = M - 1; j >= 0; j--) {
			dp[i][j] = dp[i][j + 1];
			from[i][j] = { i, j + 1 };
			if (A[i] == B[j]) {
				_cur = from[i + 1][j + 1];
				sz = dp[i + 1][j + 1];
				while (_cur.first >= 0 && A[_cur.first] <= A[i]) {
					sz--;
					_cur = from[_cur.first][_cur.second];
				}

				if (dp[i][j] < sz + 1) {
					dp[i][j] = sz + 1;
					from[i][j] = _cur;
				}

				if (ans < dp[i][j]) {
					ans = dp[i][j];
					_first = { i, j };
				}
			}
		}
	printf("%d\n", ans);
	while (_first.first != -1) {
		printf("%d ", A[_first.first]);
		_first = from[_first.first][_first.second];
	}
	return 0;
}