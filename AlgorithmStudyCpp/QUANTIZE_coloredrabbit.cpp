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
const int MAX_N = 1e2, MAX_L = 100, INF = 1e9, RANGE = 1e3+1;
map<int, int> cnt;
int N, dp[MAX_N][RANGE], A[MAX_N];
int rec(int p, int s) {
	if (p == N) return 0;
	if (!s) return INF;
	int& ret = dp[p][s];
	if (ret != -1) return ret;
	ret = INF;
	int i, j, sum = 0, cost, avg, L=1;
	for (i = p; i < N; i++, L++) {
		sum += A[i];
		avg = (double)sum / L + 0.5;
		cost = 0;
		for (j = p; j <= i; j++)
			cost += (avg - A[j]) * (avg - A[j]);
		ret = min(ret, rec(i + 1, s - 1) + cost);
	}
	return ret;
}
int main() {
	int T, i, S;
	cin >> T;
	while (T--) {
		cin >> N >> S;
		for (i = 0; i < N; i++)
			cin >> A[i];

		sort(A, A + N);
		memset(dp, -1, sizeof dp);
		cout << rec(0, S) << '\n';
	}
	return 0;
}