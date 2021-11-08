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
const int MAX_N = 1000, INF = 1e9, SWITCH=10;
int main() {
	freopen("input.txt", "r", stdin);
	double ans;
	int T, i, j, N, L, cost[MAX_N], l, r, sum, tmp;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &L);
		
		for (i = 0; i < N; i++)
			scanf("%d", &cost[i]);

		ans = INF;
		for (j = L; j <= N; j++) {
			tmp = INF;
			sum = 0;
			for (l = r = 0; r < j - 1; r++) // add j-1 elements
				sum += cost[r];

			while (r < N) { // two pointer
				sum += cost[r]; // add rightest one
				r++;

				tmp = min(tmp, sum);

				sum -= cost[l]; // sub leftest one
				l++;
			}

			ans = min(ans, (double)tmp / j);
		}
		
		printf("%.10lf\n", ans);
	}
	return 0;
}