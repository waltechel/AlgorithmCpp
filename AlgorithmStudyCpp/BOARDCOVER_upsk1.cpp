#include <bits/stdc++.h>
using namespace std;
int n, m;
const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};
bool Set(vector<vector<int>>& board, int x, int y, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int nx = x + coverType[type][i][0];
		const int ny = y + coverType[type][i][1];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			ok = false;
			continue;
		}
		if ((board[nx][ny] += delta) > 1) {
			ok = false;
		}
	}
	return ok;
}
int cover(vector<vector<int>>& board) {
	int x = -1, y = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				x = i;
				y = j;
				break;
			}
		}
		if (x != -1)break;
	}
	if (x == -1)return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		if (Set(board, x, y, type, 1))ret += cover(board);
		Set(board, x, y, type, -1);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		vector<vector<int>> v(n);
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				if (s[j] == '#')v[i].push_back(1);
				else v[i].push_back(0);
			}
		}
		cout << cover(v) << '\n';
	}
}