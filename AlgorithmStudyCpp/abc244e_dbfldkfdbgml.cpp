#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

int dp[2001][2001][2];
const int MOD = 998244353;
// dp[i][j]=(the number of ways to travel from Vertex S to Vertex j using edges i times).
// dp[i][j][x]=(the number of ways to travel from Vertex S to Vertex j using edges i times,
// in which(the number of visits to Vertex X) mod2 is x).

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int N, M, K, S, T, X;
	cin >> N >> M >> K >> S >> T >> X;
	vector<pair<int, int>> edgeList(M);
	for (int i = 0; i < M; i++) {
		cin >> edgeList[i].first >> edgeList[i].second;
	}

	// 처음에 S에서 시작하므로
	dp[0][S][0] = 1;
	for (int i = 0; i < K; i++) {
		for (pair<int, int> edge : edgeList) {
			for (int x : {0, 1}) {
				dp[i + 1][edge.second][x ^ (edge.second == X)] += dp[i][edge.first][x];
				dp[i + 1][edge.second][x ^ (edge.second == X)] %= MOD;
				dp[i + 1][edge.first][x ^ (edge.first == X)] += dp[i][edge.second][x];
				dp[i + 1][edge.first][x ^ (edge.first == X)] %= MOD;
			}
		}
	}
	// K 개까지 진행했는데 T 점에 왔고 짝수 번 사용했을 때
	cout << dp[K][T][0] << "\n";

	return 0;
}