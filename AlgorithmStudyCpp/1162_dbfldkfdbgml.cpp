#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_set>
#include<regex>

using namespace std;

/*
	2차원 dp로 풀림
	dp[i][k] i 번째 정점에 k번의 도로포장을 해서 이동한 최소 거리
*/

struct comparator {
	bool operator()(const long long* a, const long long* b) const {
		return a[2] > b[2]; 
	}
};

vector<pair<int, int>> graph[10001];
long long dp[10001][21];

long long const MAX = 1000000000000000l;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}

	for (int i = 0; i <= 10000; i++) {
		for (int j = 0; j <= 20; j++) {
			dp[i][j] = MAX;
		}
	}

	priority_queue<long long*, vector<long long*>, comparator> que;
	long long* start = new long long[3];
	start[0] = 1;
	start[1] = 0;
	dp[start[0]][start[1]] = 0;
	start[2] = dp[start[0]][start[1]];

	que.push(start);

	while (!que.empty()) {
		long long* now = que.top();
		que.pop();
		
		// 너무 커지면 무조건 줄여버림
		if (dp[now[0]][now[1]] < now[2]) {
			continue;
		}

		for (pair<int, int> edge : graph[now[0]]) {
			int next = edge.first;
			int cost = edge.second;

			// 도로포장을 안 쓰고 갈 수 있는지를 확인한다
			if (dp[next][now[1]] > dp[now[0]][now[1]] + cost) {
				dp[next][now[1]] = dp[now[0]][now[1]] + cost;
				long long* newPoint = new long long[3];
				newPoint[0] = next;
				newPoint[1] = now[1];
				newPoint[2] = dp[next][now[1]];
				que.push(newPoint);
			}

			// 도로포장을 쓰면 갈 수 있는지를 확인한다
			if (now[1] + 1 <= K && dp[next][now[1] + 1] > dp[now[0]][now[1]]) {
				dp[next][now[1] + 1] = dp[now[0]][now[1]];
				long long* newPoint = new long long[3];
				newPoint[0] = next;
				newPoint[1] = now[1] + 1;
				newPoint[2] = dp[next][now[1] + 1];
				que.push(newPoint);
			}
		}

	}

	long long answer = MAX;
	for (int i = 0; i <= K; i++) {
		answer = min(answer, dp[N][i]);
	}

	cout << answer;

	return 0;
}