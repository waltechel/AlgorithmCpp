#include <bits/stdc++.h>
using namespace std;

int c[130][130], f[130][130], d[130], n, m, wins[13], match[101][2];
vector<int> v[130];
const int INF = 1001 * 7001;
int maxFlow(int start, int end) {
	int ret = 0;
	while (true) {
		fill(d, d + 130, -1);
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < v[x].size(); i++) {
				int y = v[x][i];
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x;
					if (y == end)break;
				}
			}
		}
		if (d[end] == -1)break;
		int flow = INF;
		for (int i = end; i != start; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}

		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		ret += flow;
	}
	return ret;
}
bool canWinWith(int totalWins) {
	for (int i = 1; i < n; i++) {
		if (wins[i] >= totalWins)return false;
	}
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	for (int i = 0; i < m; i++) {
		c[0][2 + i] = 1;
		for (int j = 0; j < 2; j++) {
			c[2 + i][2 + m + match[i][j]] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		int maxWin = (i == 0 ? totalWins : totalWins - 1);
		c[2 + m + i][1] = maxWin - wins[i];
	}
	if (maxFlow(0, 1) == m)return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)cin >> wins[i];
		int l = wins[0], r = wins[0];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> match[i][j];
			}
			if (match[i][0] == 0 || match[i][1] == 0)r++;
		}
		int ans = -1;
		for (int i = 0; i < m; i++) {
			v[0].push_back(2 + i);
			v[2 + i].push_back(0);
			for (int j = 0; j < 2; j++) {
				v[2 + i].push_back(2 + m + match[i][j]);
				v[2 + m + match[i][j]].push_back(2 + i);
			}
		}
		for (int i = 0; i < n; i++) {
			v[2 + m + i].push_back(1);
			v[1].push_back(2 + m + i);
		}
		for (int i = l; i <= r; i++) {
			if (canWinWith(i)) {
				ans = i;
				break;
			}
		}

		cout << ans << '\n';
		int i2 = 2 + n + m + 1;
		for (int i = 0; i < i2; i++)v[i].clear();
	}

}