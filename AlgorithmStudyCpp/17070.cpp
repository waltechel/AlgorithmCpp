#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int map[17][17];
int answer;
int N;

/*
	대각선은 세 군데가 비어 있어야 한다.
*/

void dfs(int r1, int c1, int r2, int c2) {
	if (r2 == N && c2 == N) {
		answer++;
		return;
	}

	if (r1 == r2 && c1 + 1 == c2) {// 오른쪽이동
		if (c2 + 1 <= N && map[r2][c2 + 1] == 0) {
			dfs(r2, c2, r2, c2 + 1);// 오른쪽이동
		}
		if (r2 + 1 <= N && c2 + 1 <= N && map[r2 + 1][c2 + 1] == 0 && map[r2 + 1][c2] == 0 && map[r2][c2 + 1] == 0) {
			dfs(r2, c2, r2 + 1, c2 + 1);// 우대각이동
		}
	}
	if (r1 + 1 == r2 && c1 == c2) {// 아래쪽이동
		if (r2 + 1 <= N && map[r2 + 1][c2] == 0) {
			dfs(r2, c2, r2 + 1, c2);// 아래쪽이동
		}
		if (r2 + 1 <= N && c2 + 1 <= N && map[r2 + 1][c2 + 1] == 0 && map[r2 + 1][c2] == 0 && map[r2][c2 + 1] == 0) {
			dfs(r2, c2, r2 + 1, c2 + 1);// 우대각이동
		}
	}
	if (r1 + 1 == r2 && c1 + 1 == c2) {// 우대각이동
		if (r2 + 1 <= N && map[r2 + 1][c2] == 0) {
			dfs(r2, c2, r2 + 1, c2);// 아래쪽이동
		}
		if (r2 + 1 <= N && c2 + 1 <= N && map[r2 + 1][c2 + 1] == 0 && map[r2 + 1][c2] == 0 && map[r2][c2 + 1] == 0) {
			dfs(r2, c2, r2 + 1, c2 + 1);// 우대각이동
		}
		if (c2 + 1 <= N && map[r2][c2 + 1] == 0) {
			dfs(r2, c2, r2, c2 + 1);// 아래쪽이동
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	if (map[1][2] == 0) {
		dfs(1, 1, 1, 2);
	}
	
	cout << answer;

	return 0;
}