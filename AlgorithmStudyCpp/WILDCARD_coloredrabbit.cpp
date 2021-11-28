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
const int MAX_N = 50, INF = 1e9, MAX_L = 100;
int dp[MAX_L][MAX_L];
int rec(string& x, string& y, int a, int b) {
	if (b == y.length()) return a == x.length() || (a == x.length() - 1 && x[a] == '*');
	if (a == x.length()) return 0;
	int& ret = dp[a][b];
	if (ret != -1) return ret;
	ret = 0;

	int i;
	if (x[a] == '*') {
		ret = rec(x, y, a + 1, b); // matches no characters
		for (i = b; i < y.length(); i++) // matches [b, i] characters
			ret |= rec(x, y, a + 1, i + 1);
	}
	else if (x[a] == '?')
		ret = rec(x, y, a + 1, b + 1);
	else {
		if (x[a] == y[b])
			ret = rec(x, y, a + 1, b + 1);
	}
	return ret;
}
int main() {
	string x, y;
	vector<string> candi;
	int T, n, i, j;
	cin >> T;
	while (T--) {
		candi.clear();
		cin >> x >> n;
		for (i = 0; i < n; i++) {
			cin >> y;
			memset(dp, -1, sizeof dp);
			
			if (rec(x, y, 0, 0))
				candi.push_back(y);
		}

		// sorting
		sort(candi.begin(), candi.end()); 
		for (string& c : candi)
			cout << c << '\n';
	}
	return 0;
}