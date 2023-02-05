#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

/*
	플로이드 워셜의 최단 경로를 만족하는 간선을 유지시키면 된다.
*/

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int N, M;
	cin >> N >> M;
	vector<int*> edgeList;
	long long MAX = (1LL << 60);
	vector<vector<long long >> graph(N + 1, vector<long long>(N + 1, MAX));
	for (int i = 0; i < M; i++) {
		int* edge = new int[3];
		cin >> edge[0] >> edge[1] >> edge[2];
		edgeList.push_back(edge);
		graph[edge[0]][edge[1]] = min(graph[edge[0]][edge[1]], (long long)edge[2]);
		graph[edge[1]][edge[0]] = min(graph[edge[1]][edge[0]], (long long)edge[2]);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	// 이렇게 하면 더 비싼 간선을 제외할 수는 있음
	int answer = 0;
	//for (int i = 0; i < M; i++) {
	//	int* edge = edgeList[i];
	//	if (edge[2] > graph[edge[0]][edge[1]]) {
	//		answer++;
	//	}
	//}

	for (int i = 0; i < M; i++) {
		int* edge = edgeList[i];
		for (int j = 1; j <= N; j++) {
			if (edge[2] >= graph[edge[0]][j] + graph[j][edge[1]]) {
				answer++;
				break;
			}
		}
	}

	cout << answer;
	return 0;
}