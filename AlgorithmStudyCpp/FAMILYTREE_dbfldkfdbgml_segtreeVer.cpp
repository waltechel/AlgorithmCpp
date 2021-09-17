#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int depth[100001];
vector<int> graph[100001];
vector<int> list;
int pos[100001];
int* tree;
int maxDepthIndex;
int start;

int query(int a, int b);
void dfs(int now, int d, int prev);
void update(int i, int n);

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

		list.clear();
		for (int i = 0; i <= 100000; i++) {
			pos[i] = -1;
		}
		dfs(0, 1, 0);

		maxDepthIndex = 0;
		for (int i = 0, maxDepth = -1; i < N; i++) {
			if (depth[i] > maxDepth) {
				maxDepth = depth[i];
				maxDepthIndex = i;
			}
		}
		int len = 1;
		while (len < list.size()) {
			len *= 2;
		}
		start = len;
		len *= 2;
		tree = new int[len];
		for (int i = 0; i < len; i++) {
			tree[i] = maxDepthIndex;
		}

		for (int i = 0; i < list.size(); i++) {
			int n = list[i];
			update(start + i, n);
		}

		for (int i = 0; i < Q; i++) {
			int a, b;
			cin >> a >> b;

			int lca = query(start + pos[a], start + pos[b]);
			cout << (depth[a] - depth[lca]) + (depth[b] - depth[lca]) << "\n";
		}

	}
}

void update(int i, int n) {
	tree[i] = n;
	i /= 2;
	while (i > 0) {
		if (depth[tree[i * 2]] < depth[tree[i * 2 + 1]]) {
			tree[i] = tree[i * 2];
		} else {
			tree[i] = tree[i * 2 + 1];
		}
		i /= 2;
	}
}

void dfs(int now, int d, int prev) {
	depth[now] = d;
	list.push_back(now);
	if (pos[now] == -1) {
		pos[now] = list.size() - 1;
	}

	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (prev == next) {
			continue;
		}
		if (depth[next] == 0) {
			dfs(next, d + 1, now);
			list.push_back(now);
		}
	}

}

int query(int from, int to) {
	if (from > to) {
		int temp = from;
		from = to;
		to = temp;
	}

	int ret = start + pos[maxDepthIndex];
	while (from <= to) {
		if (from % 2 == 1) {
			if (depth[tree[from]] < depth[tree[ret]]) {
				ret = from;
			}
			from++;
		}
		if (to % 2 == 0) {
			if (depth[tree[to]] < depth[tree[ret]]) {
				ret = to;
			}
			to--;
		}
		from /= 2;
		to /= 2;
	}
	return tree[ret];
}