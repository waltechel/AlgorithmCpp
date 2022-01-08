#include <bits/stdc++.h>
using namespace std;
int a[51][51];
double d[51][101];
bool check[51][101];
queue<pair<int, int>> q;
vector<int> v[51];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision(8);
	int T;
	cin >> T;
	while (T--) {
		int n, m, start;
		cin >> n >> m >> start;
		for (int i = 1; i <= n; i++) {
			v[i].clear();
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				if (a[i][j])v[i].push_back(j);
			}
			for (int j = 1; j <= m; j++) {
				d[i][j] = 0;
				check[i][j] = false;
			}
		}
		start++;
		for (auto kk : v[start]) {
			d[kk][1] = 1.0 / v[start].size();
			check[kk][1] = true;
			q.push({ kk,1 });
		}
		while (!q.empty()) {
			int x = q.front().first, days = q.front().second;
			q.pop();
			int nextDays = days + 1;
			if (nextDays > m)continue;
			for (auto kk : v[x]) {
				if (check[kk][nextDays] == false) {
					check[kk][nextDays] = true;
					q.push({ kk,nextDays });
				}
				d[kk][nextDays] += d[x][days] * (1.0 / v[x].size());
			}
		}
		int t;
		cin >> t;
		while (t--) {
			int town;
			cin >> town;
			town++;
			double ans = d[town][m];
			/*for (int i = 1; i <= m; i++)ans += d[town][i];*/
			cout << ans << ' ';
		}
		cout << '\n';
	}


}