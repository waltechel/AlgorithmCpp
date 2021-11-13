#include <bits/stdc++.h>
using namespace std;
string s[5], temp;
int d[5][5][11];
bool ans;
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };
void dfs(int x, int y, int cnt) {
	if (temp.size() == cnt) {
		ans = true;
		return;
	}
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)continue;
		if (s[nx][ny] != temp[cnt])continue;
		if (d[nx][ny][cnt + 1])continue;
		d[nx][ny][cnt + 1] = 1;
		dfs(nx, ny, cnt + 1);
		if (ans)return;
	}
	if (ans)return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 5; i++)cin >> s[i];
		int m;
		cin >> m;
		while (m--) {
			cin >> temp;
			memset(d, 0, sizeof(d));
			ans = false;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (s[i][j] == temp[0]) {
						dfs(i, j, 1);
					}
					if (ans)break;
				}
				if (ans)break;
			}
			cout << temp << ' ';
			if (ans)cout << "YES\n";
			else cout << "NO\n";
		}
	}
}