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
#include<bitset>

using namespace std;

vector<vector<int>> DIRECTIONS = { {-1, 0}, {1, 0}, {0, -1},{0, 1} };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int R, C;
		cin >> R >> C;
		unordered_map<int, int> visited[101][101];
		char graph[101][101];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> graph[i][j];
			}
		}
		int keyset = 0;
		string keyline;
		cin >> keyline;
		if (keyline != "0") {
			for (int i = 0; i < keyline.size(); i++) {
				keyset |= (1 << ((int)(keyline[i] - 'a')));
			}
		}
		// 해당 키를 가지고 갈 수 있는 최솟값을 구한다.
		queue<int*> que;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				// 처음에 빈 공간이면 간다
				if (graph[i][j] == '.' && 
					(i == 0 || i == R - 1 || j == 0 || j == C - 1)
					) {
					int* temp = new int[4];
					temp[0] = i;
					temp[1] = j;
					temp[2] = keyset;
					temp[3] = 0;
					visited[i][j][keyset] = 0;
					que.push(temp);
				}

				// 처음에 돈인 경우도 간다
				if (graph[i][j] == '$' &&
					(i == 0 || i == R - 1 || j == 0 || j == C - 1)
					) {
					int* temp = new int[4];
					temp[0] = i;
					temp[1] = j;
					temp[2] = keyset;
					temp[3] = 0;
					visited[i][j][keyset] = 0;
					que.push(temp);
				}

				// 처음에 열쇠인 경우도 간다
				if (graph[i][j] >= 'a' && graph[i][j] <= 'z' &&
					(i == 0 || i == R - 1 || j == 0 || j == C - 1)
					) {
					int* temp = new int[4];
					temp[0] = i;
					temp[1] = j;
					keyset |= (1 << ((int)(graph[i][j] - 'a')));
					temp[2] = keyset;
					temp[3] = 0;
					visited[i][j][keyset] = 0;
					que.push(temp);

					// 처음부터 다시 통과
					for (int a = 0; a < R; a++) {
						for (int b = 0; b < C; b++) {
							if ((graph[a][b] == '.' || 
								(graph[a][b] >= 'A' && graph[a][b] <= 'Z'
									&& ((1 << ((int)(graph[a][b] - 'a'))) & keyset) != 0)) &&
								(a == 0 || a == R - 1 || b == 0 || b == C - 1) 
								
								) {
								int* temp = new int[4];
								temp[0] = a;
								temp[1] = b;
								temp[2] = keyset;
								temp[3] = 0;
								visited[a][b][temp[2]] = 0;
								que.push(temp);
							}
						}
					}

				}

				// 처음에 벽인데 처음에 열쇠로 따고 들어갈 수 있으면 간다
				if (graph[i][j] >= 'A' && graph[i][j] <= 'Z'
					&& ((1 << ((int)(graph[i][j] - 'a'))) & keyset) != 0 &&
					(i == 0 || i == R - 1 || j == 0 || j == C - 1)
					) {
					int* temp = new int[4];
					temp[0] = i;
					temp[1] = j;
					temp[2] = keyset;
					temp[3] = 0;
					visited[i][j][keyset] = 0;
					que.push(temp);
				}
			}
		}

		while (!que.empty()) {
			int* now = que.front();
			que.pop();
			for (int d = 0; d < DIRECTIONS.size(); d++) {
				int newRow = now[0] + DIRECTIONS[d][0];
				int newCol = now[1] + DIRECTIONS[d][1];
				if (newRow >= 0 && newRow < R && newCol >= 0 && newCol < C) {
					// 아예 빈 데면 통과 가능
					if (graph[newRow][newCol] == '.' && visited[newRow][newCol][now[2]] == 0) {
						int* next = new int[4];
						next[0] = newRow;
						next[1] = newCol;
						next[2] = now[2];
						next[3] = now[3] + 1;
						visited[newRow][newCol][next[2]] = next[3];
						que.push(next);
					}
					// 돈이면 통과 가능
					if (graph[newRow][newCol] == '$' && visited[newRow][newCol][now[2]] == 0) {
						int* next = new int[4];
						next[0] = newRow;
						next[1] = newCol;
						next[2] = now[2];
						next[3] = now[3] + 1;
						visited[newRow][newCol][next[2]] = next[3];
						que.push(next);
					}
					// 열쇠면 통과 가능
					if (graph[newRow][newCol] >= 'a' && graph[newRow][newCol] <= 'z' && visited[newRow][newCol][now[2]] == 0) {
						int* next = new int[4];
						next[0] = newRow;
						next[1] = newCol;
						next[2] = now[2] | (1 << ((int)(graph[newRow][newCol] - 'a')));
						next[3] = now[3] + 1;
						visited[newRow][newCol][next[2]] = next[3];
						que.push(next);

						// 처음부터 다시 통과
						for (int i = 0; i < R; i++) {
							for (int j = 0; j < C; j++) {
								if ((graph[i][j] == '.' ||
									(graph[i][j] >= 'A' && graph[i][j] <= 'Z'
										&& ((1 << ((int)(graph[i][j] - 'a'))) & next[2]) != 0))
									&&
									(i == 0 || i == R - 1 || j == 0 || j == C - 1)									
									) {
									int* temp = new int[4];
									temp[0] = i;
									temp[1] = j;
									temp[2] = next[2];
									temp[3] = 0;
									visited[i][j][temp[2]] = 0;
									que.push(temp);
								}
							}
						}
					}
					// 문인데 열쇠가 있으면 통과가 가능
					if (graph[newRow][newCol] >= 'A' && graph[newRow][newCol] <= 'Z' 
						&& visited[newRow][newCol][now[2]] == 0
						&& ((1 <<  ((int) (graph[newRow][newCol] - 'a'))) & now[2]) != 0
						) {
						int* next = new int[4];
						next[0] = newRow;
						next[1] = newCol;
						next[2] = now[2];
						next[3] = now[3] + 1;
						visited[newRow][newCol][next[2]] = next[3];
						que.push(next);
					}
				}
			}
		}

		int answer = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (graph[i][j] == '$' && visited[i][j].size() != 0) {
					answer++;
				}
			}
		}
		cout << answer << "\n";

	}



	return 0;

}