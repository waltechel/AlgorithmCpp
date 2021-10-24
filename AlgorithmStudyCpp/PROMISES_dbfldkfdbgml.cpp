#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int MAX_VALUE = 2000000000;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		int V, M, N;

		cin >> V >> M >> N;

		vector<pair<int, int>> graph[200];
		for (int i = 0; i < M; i++) {
			int from, to, cost;
			cin >> from >> to >> cost;
			graph[from].push_back(make_pair(to, cost));
			graph[to].push_back(make_pair(from, cost));
		}

		int answer = 0;
		for (int i = 0; i < N; i++) {
			int from, to, diff;
			cin >> from >> to >> diff;
			int* dist = new int[V];
			for (int j = 0; j < V; j++) {
				dist[j] = MAX_VALUE;
			}

			// 매번 다익스트라를 갖다 돌림
			dist[from] = 0;
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
			pq.push(make_pair(dist[from], from));
			while (!pq.empty()) {
				pair<int, int> p = pq.top();
				pq.pop();
				if (dist[p.second] < p.first) {
					continue;
				}
				for (int j = 0; j < graph[p.second].size(); j++) {
					int next = graph[p.second].at(j).first;
					int cost = graph[p.second].at(j).second;
					if (dist[next] > dist[p.second] + cost) {
						dist[next] = dist[p.second] + cost;
						pq.push(make_pair(dist[next], next));
					}
				}
			}

			// 기존 최단 경로보다 내 간선이 작으면 그냥 넣어
			if (dist[to] > diff) {
				graph[from].push_back(make_pair(to, diff));
				graph[to].push_back(make_pair(from, diff));
			// 아님 말고
			} else {
				answer++;
			}

		}

		cout << answer << "\n";

	}

	return 0;
}

