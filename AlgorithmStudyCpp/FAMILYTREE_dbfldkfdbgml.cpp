#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int depth[100001];
int parent[100001][17];
vector<int> graph[100001];

int query(int a, int b);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		int N, Q;
		cin >> N >> Q;
		for (int i = 0; i < N; i++) {
			graph[i].clear();
		}
		for (int i = 1, n = 0; i < N; i++) {
			cin >> n;
			graph[i].push_back(n);
			graph[n].push_back(i);
		}

		for (int i = 0; i < N; i++) {
			depth[i] = 0;
		}
		depth[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 17; j++) {
				parent[i][j] = 0;
			}
		}
		queue<int*> que;
		que.push(new int[2] {0, 1});
		while (!que.empty()) {
			int* temp = que.front();
			que.pop();
			int now = temp[0];
			int d = temp[1];
			depth[now] = d;
			for (int i = 0; i < graph[now].size(); i++) {
				int next = graph[now][i];
				if (depth[next] == 0) {
					parent[next][0] = now;
					que.push(new int[2] { next, d + 1 });
				}
			}
		}

		for (int k = 1; k < 17; k++) {
			for (int i = 0; i < N; i++) {
				parent[i][k] = parent[parent[i][k - 1]][k - 1];
			}
		}

		for (int i = 0; i < Q; i++) {
			int a, b;
			cin >> a >> b;
			int lca = query(a, b);
			cout << (depth[a] - depth[lca]) + (depth[b] - depth[lca]) << "\n";
		}

	}
}

int query(int a, int b) {
	if (depth[a] < depth[b]) {
		int temp = a;
		a = b;
		b = temp;
	}

	for (int i = 16; i >= 0; i--) {
		if (depth[parent[a][i]] >= depth[b]) {
			a = parent[a][i];
		}
	}
	if (a == b) {
		return a;
	}
	for (int i = 16; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}

	return parent[a][0];
}