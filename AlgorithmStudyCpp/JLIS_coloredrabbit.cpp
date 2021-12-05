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
const int MAX_N = 105, MAX_L = 100;
const ll INF = (1LL << 45) - 1;
int n, m, dp[MAX_N][MAX_N];
ll a[MAX_N], b[MAX_N];
int rec(int p1, int p2) {
	if (p1 == n && p2 == m) return 0;
	int& ret = dp[p1][p2];
	if (ret != -1) return ret;
	int i, j;
	ll c = max(a[p1], b[p2]);

	ret = 0;
	// 지금까지 구성한 JIS 중 마지막 위치에 가장 큰 값 추가
	for (i = p1 + 1; i < n; i++)
		if (c < a[i])
			ret = max(ret, rec(i, p2) + 1);

	for (i = p2 + 1; i < m; i++)
		if (c < b[i])
			ret = max(ret, rec(p1, i) + 1);
	return ret;
}
int main() {
	int T, i, j, ans;
	a[0] = b[0] = -INF;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (i = 1; i <= n; i++) scanf("%lld", &a[i]);		
		for (i = 1; i <= m; i++) scanf("%lld", &b[i]);
		a[n + 1] = b[m + 1] = INF;
		a[n + 2] = b[m + 2] = -INF;
		n += 2, m += 2;

		memset(dp, -1, sizeof dp);
		ans = 0;
		for (i = 0; i < n; i++) for (j = 0; j < m; j++)
			if (a[i] != b[j])
				ans = max(ans, rec(i, j) + (i > 0) + (j > 0) - 1); // INF 제거
		printf("%d\n", ans);
	}
	return 0;
}