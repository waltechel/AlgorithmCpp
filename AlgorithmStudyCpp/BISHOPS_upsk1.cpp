#include <bits/stdc++.h>
using namespace std;

int c[140][140], f[140][140], d[140], n, start;
int dx[2] = { 1,1 };
int dy[2] = { -1,1 };
int id[2][8][8];
string board[8];

vector<int> v[130];
const int INF = 1001 * 7001;
int maxFlow(int start, int end) {
	int ret = 0;
	while (true) {
		fill(d, d + 140, -1);
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
int placeBishops() {
	memset(id, -1, sizeof(id));
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	for (int i = 0; i < 130; i++)v[i].clear();
	start = 2;
	int temp;
	for (int dir = 0; dir < 2; dir++) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (board[x][y] == '.' && id[dir][x][y] == -1) {
					int cx = x, cy = y;
					while (cx >= 0 && cx < n && cy >= 0 && cy < n) {
						if (board[cx][cy] == '*')break;
						id[dir][cx][cy] = start;
						cx += dx[dir];
						cy += dy[dir];
					}
					start++;
				}
			}
		}
		if (dir == 0) {
			for (int j = 2; j < start; j++) {
				v[0].push_back(j);
				v[j].push_back(0);
				c[0][j] = 1;
				temp = start;
			}
		}
		if (dir == 1) {
			for (int j = temp; j < start; j++) {
				v[j].push_back(1);
				v[1].push_back(j);
				c[j][1] = 1;
			}
		}
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (board[x][y] == '.') {
				int from = id[0][x][y], to = id[1][x][y];
				v[from].push_back(to);
				v[to].push_back(from);
				c[from][to] = 1;
			}
		}
	}

	return maxFlow(0, 1);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++)cin >> board[i];
		int cntStar = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == '*')cntStar++;
			}
		}
		if (cntStar == n * n) {
			cout << 0 << '\n';
			continue;
		}
		cout << placeBishops() << '\n';

		//for (int i = 0; i < n; i++) {
		//	cout << setw(2)<<board[i] << '\n';
		//}
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		cout << setw(3) << id[0][i][j];
		//	}
		//	cout << '\n';
		//}
		//cout << '\n';
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		cout << setw(3) << id[1][i][j];
		//	}
		//	cout << '\n';
		//}
		//cout << '\n';
	}

}