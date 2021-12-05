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
const int MAX_N = 500, INF = 1e9, MAX_L = 100;
int main() {
	int T, i, j, nums[MAX_N], n, dp[MAX_N], ans;
	cin >> T;
	while (T--) {
		cin >> n;
		ans = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
			dp[i] = 1;
			for (j = 0; j < i; j++)
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], dp[j] + 1);
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}