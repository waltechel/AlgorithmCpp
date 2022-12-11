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

// modern c++
// 모든 점을 다 알기 위해서는 BFS를 활용한 경로 되추적을 해보자

using namespace std;

int N, X, Y;
vector<vector<int>> graph;
stack<int> history;

void dfs(int now, int prev) {
	history.push(now);
	if (now == X) {
		while (!history.empty()) {
			cout << history.top() << " ";
			history.pop();
		}
		return;
	}

	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (next == prev) {
			continue;
		}
		dfs(next, now);
		if (!history.empty()) {
			history.pop();
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> X >> Y;
	graph.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	dfs(Y, 0);

	return 0;
}