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
const int MAX_N = 1e4, MAX_L = 100, INF = 1e9;
string s;
int dp[MAX_N];
int rec(int p) {
	if (p == s.length()) return 0;
	int& ret = dp[p];
	if (ret != -1) return ret;
	ret = INF;
	if (p + 2 < s.length()) {
		int i, cost, d = s[p + 1] - s[p];
		bool _same = s[p] == s[p + 1], _common_diff = 1, _two_balanced = 1;
		for (i = 2; i < 5 && p + i < s.length(); i++) {
			_same &= s[p] == s[p + i]; // 모든 수 같음
			_common_diff &= d == s[p + i] - s[p + i - 1]; // 등차
			_two_balanced &= s[p + i % 2] == s[p + i]; // 54545

			if (_same)
				cost = 1;
			else if (_common_diff)
				cost = abs(d) == 1 ? 2 : 5;
			else
				cost = _two_balanced ? 4 : 10;
			ret = min(ret, rec(p + i + 1) + cost);
		}
	}
	return ret;
}
int main() {
	int T, i, j, ans;
	cin >> T;
	while (T--) {
		cin >> s;
		memset(dp, -1, sizeof dp);
		cout << rec(0) << '\n';
	}
	return 0;
}