#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	
	int N, M;
	cin >> N >> M;
	vector<vector<bool>> graph(N + 1, vector<bool>(N + 1, false));
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		graph[from][to] = true;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][k] && graph[k][j]) {
					graph[i][j] = true;
				}
			}
		}
	}

	int answer = 0;
	int middle = (N + 1) / 2 - 1;
	for (int i = 1; i <= N; i++) {
		int cntOfBig = 0; // 나보다 큰 것들의 수
		int cntOfSmall = 0; // 나보다 작은 것들의 수
		for (int j = 1; j <= N; j++) {
			if (graph[i][j]) {
				cntOfBig++;
			}
			if (graph[j][i]) {
				cntOfSmall++;
			}
		}
		if (cntOfSmall > middle) {
			answer++;
			continue;
		}
		if (cntOfBig > middle) {
			answer++;
			continue;
		}
	}

	cout << answer;

	return 0;
}