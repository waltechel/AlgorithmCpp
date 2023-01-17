#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>graph[30001];
int order[30001];
bool isAp[30001];
int index;

void init() {
	for (int i = 0; i <= 30000; i++) {
		graph[i].clear();
	}
	for (int i = 0; i <= 30000; i++) {
		order[i] = 0;
	}
	for (int i = 0; i <= 30000; i++) {
		isAp[i] = false;
	}
	index = 0;
}

/*
	targan 의 단절점 찾기 알고리즘
*/
int dfs(int now, int parent) {
	if (order[now]) {
		return order[now];
	}

	int cnt = 0;
	order[now] = index++;
	int ret = order[now];
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (parent == next) {
			continue;
		}
		// 만약 방문한 곳을 또 가야 한다면 사이클이 존재한다. 사이클은 minOrder로 칠해놓는다.
		if (order[next] != 0) {
			ret = min(ret, order[next]);
		} else {
			int candi = dfs(next, now);
			if (parent != 0 && candi >= order[now]) {
				isAp[now] = true;
			}
			ret = min(ret, candi);
			cnt++;
		}
	}

	if (parent == 0 && cnt > 1) {
		isAp[now] = true;
	}

	return ret;

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		init();

		int V, E;
		cin >> V >> E;
		for (int i = 0; i < E; i++) {
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}

		index = 1;
		for (int i = 1; i <= V; i++) {
			if (order[i] == 0) {
				dfs(i, 0);
			}
		}

		int answerCount = 0;
		for (int i = 0; i <= V; i++) {
			if (isAp[i]) {
				answerCount++;
			}
		}
		if (answerCount) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}