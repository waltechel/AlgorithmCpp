#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<unordered_set>
#include<regex>
#include <bitset>

using namespace std;
int graph[101][101];
vector<vector<int>> DIRECTIONS = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}  }; // 상 하 우 좌
/*
	BFS로 색칠한 다음
	그곳을 크루스컬로 돌려서 풀어본다
	간선을 매번 갱신해줘야 할 거 같다
*/

int parent[11];
int find(int i) {
	if (parent[i] == i)
		return i;
	return parent[i] = find(parent[i]);
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

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				graph[i][j] = -1;
			}
		}
	}

	int color = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == -1) {
				queue<pair<int, int>> q;
				q.push({ i, j });

				while (!q.empty()) {
					int row = q.front().first;
					int col = q.front().second;
					graph[row][col] = color;
					q.pop();

					for (int d = 0; d < 4; d++) {
						int newRow = row + DIRECTIONS[d][0];
						int newCol = col + DIRECTIONS[d][1];

						if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && graph[newRow][newCol] == -1) {
							q.push({ newRow, newCol });
						}
					}
				}
				color++;
			}
		}
	}

	// 각 정점을 조회하면서 다른 정점으로 갈 수 있는 최단 거리를 찾아서 넣는다
	vector<int*> edgeList;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] != 0) {
				int from = graph[i][j];

				for (int d = 0; d < 4; d++) {
					int newRow = i;
					int newCol = j;
					newRow += DIRECTIONS[d][0];
					newCol += DIRECTIONS[d][1];
					int distance = 0;
					if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && graph[newRow][newCol] == 0) {
						while (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && graph[newRow][newCol] == 0) {
							distance++;
							newRow += DIRECTIONS[d][0];
							newCol += DIRECTIONS[d][1];
						}
						if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && graph[newRow][newCol] != from) {
							int to = graph[newRow][newCol];
							if (distance >= 2 && to != 0) {
								int* edge = new int[3];
								edge[0] = from;
								edge[1] = to;
								edge[2] = distance;
								edgeList.push_back(edge);
							}
						}
					}
				}
			}
		}
	}

	

	sort(edgeList.begin(), edgeList.end(), [](const int* a, const int* b) {
		return a[2] < b[2];
	});

	//cout << "\n";
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << graph[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//for (int* edge : edgeList) {
	//	cout << edge[0] << " " << edge[1] << " " << edge[2] << "\n";
	//}

	int answer = 0;
	for (int i = 0; i <= 10; i++) {
		parent[i] = i;
	}
	for (int* edge : edgeList) {
		// 여기서 edgeList를 가지고 크루스칼 알고리즘을 구현
		if (find(edge[0]) != find(edge[1])) {
			merge(edge[0], edge[1]);
			answer += edge[2];
		}
	}
	bool nofind = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] != 0) {
				if (find(graph[i][j]) != 1) {
					nofind = true;
				}
			}
		}
	}
	if (nofind) {
		cout << "-1";
	} else {
		cout << answer;
	}

	return 0;

}