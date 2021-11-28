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
using ll = long long;
using namespace std;
const int N = 16, INF = 1e9, SWITCH=10;
vector<vector<int>> adj{
	{0,1,2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}
};
int back(int p, int board[N]) {
	if (p == SWITCH) {
		int i, valid = 1;
		for (i = 0; i < N; i++)
			valid &= board[i] == 0;
		return valid ? 0 : INF;
	}

	int i, tmp[N], ret = back(p + 1, board); // no press
	memcpy(tmp, board, sizeof tmp);
	for (i = 1; i < 4; i++) { // press i times
		for (int& pos : adj[p])
			tmp[pos] = (tmp[pos] + 1) % 4; // rotate
		ret = min(ret, back(p + 1, tmp) + i);
	}
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	
	int T, i, j, board[N], ans = INF;
	scanf("%d", &T);
	while (T--) {
		for (i = 0; i < N; i++) {
			scanf("%d", &board[i]);
			board[i] = (board[i] / 3) % 4; // modify data to 4 section
		}
		ans = back(0, board);
		printf("%d\n", ans == INF ? -1 : ans);
	}
	return 0;
}