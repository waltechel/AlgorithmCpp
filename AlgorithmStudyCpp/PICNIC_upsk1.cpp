#include <bits/stdc++.h>
using namespace std;
int n;
bool areFriends[10][10];
int countPairings(bool taken[10]) {
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1)return 1;
	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				areFriends[i][j] = false;
			}
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			areFriends[x][y] = areFriends[y][x] = true;
		}
		bool taken[10] = { false, };
		cout << countPairings(taken) << '\n';
	}
}