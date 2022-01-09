#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX_N = 101, MAX_W = 1001;
char name[MAX_N][21];
int N, W, V[MAX_N], D[MAX_N], dp[MAX_N][MAX_W];
vector<int> ans;
int rec(int p, int w) {
	if (p == N || w == 0) return 0;
	int& ret = dp[p][w];
	if (ret != -1) return ret;
	ret = rec(p + 1, w);
	if (w >= V[p])
		ret = max(ret, rec(p + 1, w - V[p]) + D[p]);
	return ret;
}
void go(int p, int w) {
	if (p == N || w == 0) return;
	int& ret = dp[p][w];
	if (ret == rec(p + 1, w))
		go(p + 1, w);
	else {
		ans.push_back(p);
		go(p + 1, w - V[p]);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	int T, i;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d\n", &N, &W);
		for (i = 0; i < N; i++)
			scanf("%s%d%d\n", name[i], &V[i], &D[i]);
		memset(dp, -1, sizeof dp);
		printf("%d ", rec(0, W));

		ans.clear();
		go(0, W);
		printf("%d\n", ans.size());
		for (int& idx : ans)
			puts(name[idx]);
	} 
	return 0;
}