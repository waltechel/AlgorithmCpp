#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_set>

/* 
You are given an undirected graph G with N verticesand M edges.
G is simple(it has no self - loops and multiple edges) and connected.

For i = 1, 2, …, M, the i - th edge is an undirected edge{ ui,vi } connecting Vertices ui and vi.

Construct two spanning trees T1 and T2 of G that satisfy both of the two conditions below.
(T1 and T2 do not necessarily have to be different spanning trees.)

T1 satisfies the following.

If we regard T1 as a rooted tree rooted at Vertex 1, for any edge{ u,v } of G not contained in T1,
one of uand v is an ancestor of the other in T1.

T2 satisfies the following.

If we regard T2 as a rooted tree rooted at Vertex 1, there is no edge{ u,v } of G not contained in T2
​such that one of uand v is an ancestor of the other in T2.

We can show that there always exists T1and T2 that satisfy the conditions above.
*/

using namespace std;

vector<int> graph[200001];
bool visited[200005];
vector<pair<int, int>> T1, T2;

void dfs(int now) {
	visited[now] = true;
	for (auto next : graph[now]) {
		if (visited[next] == false) {
			T1.push_back({ now, next });
			dfs(next);
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	dfs(1);
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
	queue<int> queue;
	queue.push(1);

	while (!queue.empty()) {
		int now = queue.front();
		visited[now] = true;
		queue.pop();
		for (auto next : graph[now]) {
			if (visited[next] == false) {
				T2.push_back({ now, next });
				visited[next] = true;
				queue.push(next);
			}
		}
	}

	for (auto p : T1) {
		cout << p.first << " " << p.second << "\n";
	}
	for (auto p : T2) {
		cout << p.first << " " << p.second << "\n";
	}

	return 0;
}