#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>

using namespace std;

vector<int*> direction = { 
	new int[3]{0, 0, 1},
	new int[3]{0, 0, -1},
	new int[3]{0, 1, 0},
	new int[3]{0, -1, 0},
	new int[3]{1, 0, 0},
	new int[3]{-1, 0, 0}
};

int*** graph;
bool isSafe(int h, int r, int c);
int M, N, H;

int main() {

	cin >> N >> M >> H;

	graph = new int** [H];
	for (int i = 0; i < H; i++) {
		graph[i] = new int* [M];
		for (int j = 0; j < M; j++) {
			graph[i][j] = new int[N];
			for (int k = 0; k < N; k++) {
				cin >> graph[i][j][k];
			}
		}
	}

	queue<int*> q;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (graph[i][j][k] == 1) {
					q.push(new int[3]{ i, j, k });
				}
			}
		}
	}

	while (!q.empty()) {
		int* now = q.front();
		q.pop();
		for (int d = 0; d < direction.size(); d++) {
			int newH = now[0] + direction[d][0];
			int newR = now[1] + direction[d][1];
			int newC = now[2] + direction[d][2];
			if (isSafe(newH, newR, newC) && (graph[newH][newR][newC] == 0 || (graph[newH][newR][newC] > graph[now[0]][now[1]][now[2]] + 1))) {
				graph[newH][newR][newC] = graph[now[0]][now[1]][now[2]] + 1;
				q.push(new int[3]{ newH, newR, newC });
			}
		}
	}

	bool isCompleted = true;
	int answer = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (answer < graph[i][j][k]) {
					answer = graph[i][j][k];
				}
				if (graph[i][j][k] == 0) {
					isCompleted = false;
				}
			}
		}
	}

	if (isCompleted) {
		cout << answer - 1 << "";
	} else {
		cout << -1 << "";
	}

	return 0;
}

bool isSafe(int h, int r, int c) {
	if (h >= 0 && h < H && 0 <= r && r < M && 0 <= c && c < N) {
		return true;
	} else {
		return false;
	}
}