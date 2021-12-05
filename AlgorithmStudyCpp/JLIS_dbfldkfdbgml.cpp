#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_NUM = 200;
int answer;
int N, M;
int dp[200][200][200];
vector<int> graph[200];

int dfs(int now, int ca, int cb);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> M;
		int A[200];
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int j = 100; j < 100 + M; j++) {
			cin >> A[j];
		}
		for (int i = 0; i < MAX_NUM; i++) {
			graph[i].clear();
		}

		for (int i = 0; i < MAX_NUM; i++) {
			if (i < N) {
				for (int j = i + 1; j < N; j++) {
					if (A[i] < A[j]) {
						graph[i].push_back(j);
					}
				}
				for (int j = 100; j < 100 + M; j++) {
					if (A[i] < A[j]) {
						graph[i].push_back(j);
					}
				}
			} else if (i >= 100 && i < 100 + M) {
				for (int j = 0; j < N; j++) {
					if (A[i] < A[j]) {
						graph[i].push_back(j);
					}
				}
				for (int j = i + 1; j < 100 + M; j++) {
					if (A[i] < A[j]) {
						graph[i].push_back(j);
					}
				}
			}
		}
		for (int i = 0; i < 200; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					dp[i][j][k] = 0;
				}
			}
		}

		for (int i = 0; i < 200; i++) {
			if (i < N) {
				dp[i][i][0] = dfs(i, i, 0);
			}
			if ((100 <= i && i < 100 + M)) {
				dp[i][0][i - 100] = dfs(i, 0, i - 100);
			}
		}

		answer = 0;
		for (int i = 0; i < 200; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					answer = max(answer, dp[i][j][k]);
				}
			}
		}
		cout << answer << "\n";
	}

	return 0;
}

int dfs(int now, int ca, int cb) {
	if (dp[now][ca][cb] != 0) {
		return dp[now][ca][cb];
	}
	dp[now][ca][cb] = 1;
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (next < N && ca <= next) {
			dp[now][ca][cb] = max(dp[now][ca][cb], dfs(next, next, cb) + 1);
		}
		if ((100 <= next && next < 100 + M) && cb <= next - 100) {
			dp[now][ca][cb] = max(dp[now][ca][cb], dfs(next, ca, next - 100) + 1);
		}
	}
	return dp[now][ca][cb];
}
