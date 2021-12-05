#include <bits/stdc++.h>
using namespace std;
string s, s2;
int d[101][101];
int solve(int i, int j) {
	if (i == s.size() && j == s2.size())return 1;
	if (i >= s.size())return 0;
	if (d[i][j] != -1)return d[i][j];
	d[i][j] = 0;
	if (j < s2.size()) {
		if (s[i] == '?' || (s[i] == s2[j])) {
			d[i][j] = max(d[i][j], solve(i + 1, j + 1));
		}
	}
	if (s[i] == '*') {
		d[i][j] = max(d[i][j], solve(i + 1, j));
		if (j < s2.size()) {
			d[i][j] = max({ d[i][j],solve(i,j + 1),solve(i + 1,j + 1) });
		}
	}
	return d[i][j];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> s;
		int n;
		cin >> n;
		vector<string> ans;
		for (int i = 0; i < n; i++) {
			cin >> s2;
			memset(d, -1, sizeof(d));
			if (solve(0, 0) == 1) {
				ans.push_back(s2);
			}
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)cout << ans[i] << '\n';
	}
}