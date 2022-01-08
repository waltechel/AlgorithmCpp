#include <bits/stdc++.h>
using namespace std;
int n, m;
int d[101][1001];
pair<int, int> from[101][1001];
struct A {
	string name;
	int vol, val;
};
A a[101];
int solve(int i, int j) {
	if (i >= n)return 0;
	if (d[i][j] != -1)return d[i][j];
	d[i][j] = solve(i + 1, j);
	from[i][j] = { i + 1,j };
	if (j >= a[i].vol) {
		if (d[i][j] < solve(i + 1, j - a[i].vol) + a[i].val) {
			d[i][j] = solve(i + 1, j - a[i].vol) + a[i].val;
			from[i][j] = { i + 1,j - a[i].vol };
		}
	}
	return d[i][j];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= m; j++) {
				d[i][j] = -1;
			}
		}
		for (int i = 0; i < n; i++)cin >> a[i].name >> a[i].vol >> a[i].val;
		cout << solve(0, m) << ' ';
		int i = 0, j = m;
		vector<int> ans;
		while (i < n) {
			if (from[i][j].second < j)ans.push_back(i);
			j = from[i][j].second; i++;
		}
		cout << ans.size() << '\n';
		for (auto kk : ans)cout << a[kk].name << '\n';
	}


}