#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>

using namespace std;

const int MAX_VALUE = 2000000000;

int parent[2000];
int find(int now);
void merge(int a, int b);

bool comparator(const tuple<int, int, int> a, const tuple<int, int, int> b) {
	return get<2>(a) < get<2>(b);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		int N, M;

		cin >> N >> M;
		int answer = MAX_VALUE;
		vector<tuple<int, int, int>> graph;
		for (int i = 0; i < M; i++) {
			int from, to, cost;
			cin >> from >> to >> cost;
			graph.push_back(make_tuple(from, to, cost));
		}

		sort(graph.begin(), graph.end(), comparator);
		// 여기를 속도로 봐도 괜찮다.
		// 속도는 1000 이하의 음이 아닌 정수이다.
		// 미니멈이 갱신되지 않는다면 바로 넘어간다.
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				parent[j] = j;
			}
			int minimum = get<2>(graph[i]);
			int maximum = get<2>(graph[i]);
			bool flag = false;
			for (int j = i; j < graph.size(); j++) {
				tuple<int, int, int> edge = graph[j];
				int from = get<0>(edge);
				int to = get<1>(edge);
				int cost = get<2>(edge);
				if (find(from) != find(to)) {
					merge(from, to);
					maximum = cost;
				}
				if (find(0) == find(N - 1)) {
					int candi = maximum - minimum;
					answer = min(answer, candi);
					break;
				}
				// 끝까지 봤는데도 이제는 답을 찾을 수 없는 경우
				if (j == graph.size() - 1 && find(0) != find(N - 1)) {
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}

		cout << answer << "\n";

	}

	return 0;
}


void merge(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);
	if (rootA < rootB) {
		parent[rootB] = rootA;
	} else {
		parent[rootA] = rootB;
	}
}

int find(int now) {
	if (parent[now] == now) {
		return now;
	} else {
		return parent[now] = find(parent[now]);
	}
}

