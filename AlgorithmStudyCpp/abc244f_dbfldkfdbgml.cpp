#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

// 비트마스크 DP
// int [state][i] dp : i 번째 점까지 왔을 때 S 상태일 때 goodpath의 길이
// 문제의 답 int[state][점] 까지의 합
// BFS를 이용해서 탐색해서 갱신해버림

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int N, M;
	cin >> N >> M;
	const int INF = 1 << 30;
	vector<vector<int>> dp(1 << N, vector<int>(N, INF));
	vector<int>* graph = new vector<int>[N];
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	dp[0][0] = 0;
	for (int i = 0; i < N; i++) {
		dp[1 << i][i] = 1;
	}

	queue<pair<int, int>> queue;
	for (int i = 0; i < N; i++) {
		queue.push({ 1 << i, i });
	}
	while (queue.size()) {
		int state = queue.front().first;
		int now = queue.front().second;
		queue.pop();
		for (int next : graph[now]) {
			int nextState = state ^ (1 << next);
			if (dp[nextState][next] < INF) {
				continue;
			}
			dp[nextState][next] = dp[state][now] + 1;
			queue.push({ nextState, next });
		}
	}

	long long answer = 0;
	for (int i = 0; i < (1 << N); i++) {
		int candi = INF;
		for (int j = 0; j < N; j++) {
			candi = min(dp[i][j], candi);
		}
		answer += candi;
	}
	cout << answer;
	return 0;
}