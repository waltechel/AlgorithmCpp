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
const int MAX_N = 2e4 + 1, INF = 1e9, SWITCH = 10, SZ = 60;
int main() {
	int T, N, i, j, a[MAX_N], ans, w;
	stack<int> stk;
	scanf("%d\n", &T);
	while (T--) {
		// init
		ans = 0;
		while (!stk.empty()) stk.pop();

		scanf("%d", &N);
		for (i = 0; i <= N; i++) {
			if (i == N) a[i] = 0; // dummy
			else scanf("%d", &a[i]);

			// stack indices by increasing order on the value
			while (!stk.empty() && a[stk.top()] >= a[i]) {
				j = stk.top(); stk.pop();
				if (stk.empty()) // is a smallest index in [0, i]
					w = i;
				else
					w = i - stk.top() - 1; // other case
				ans = max(ans, w * a[j]);
			}
			stk.push(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}