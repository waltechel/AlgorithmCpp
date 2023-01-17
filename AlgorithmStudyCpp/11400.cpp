#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>graph[100001];
int order[100001];
vector<pair<int, int>> edgeList;
int index;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) {
		return a.first < b.first;
	} else {
		return a.second < b.second;
	}
}

/*
	targan 의 단절점 찾기 알고리즘
*/
int dfs(int now, int parent) {
	if (order[now]) {
		return order[now];
	}

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
			if (candi > order[now]) {
				edgeList.push_back({ min(now, next), max(now, next) });
			}
			ret = min(ret, candi);
		}
	}

	return ret;

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

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

	sort(edgeList.begin(), edgeList.end(), comp);

	cout << edgeList.size() << "\n";

	for (pair<int, int> edge : edgeList) {
		cout << edge.first << " " << edge.second << "\n";
	}

	return 0;
}