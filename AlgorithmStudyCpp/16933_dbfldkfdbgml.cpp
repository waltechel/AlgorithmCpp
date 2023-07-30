#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_set>
#include<regex>

using namespace std;

/*
	3차원으로 풀림
	graph[i][j][k] - i, j 곳을 k번만에 깨서 갈 수 있어야 한다
	이 문제의 특징은 깰 수 있는 곳은 반드시 짝수 번에 가서 깨야 한다
	만약에 현재 위치가 짝수(밤)이면 +1이 아니라 +2를 더해서 깨야 함
*/

vector<vector<int>> DIRECTIONS = { {-1, 0}, {1, 0}, {0, 1 }, {0, -1} };

int dp[1001][1001][11];
char graph[1001][1001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int R, C, K;
	cin >> R >> C >> K;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> graph[i][j];
		}
	}

	/*cout << "graph 검증\n";
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			for (int k = 0; k <= 10; k++) {
				dp[i][j][k] = 20000000;
			}
		}
	}

	queue<int*> que;
	dp[1][1][0] = 1;
	int* start = new int[4];
	start[0] = 1; // i
	start[1] = 1; // j
	start[2] = 0; // k
	start[3] = 1; // depth
	que.push(start);

	while (!que.empty()) {
		int* now = que.front();
		que.pop();

		//cout << "now is " << now[0] << ", " << now[1] << ", " << now[2] << ", " << now[3] << "\n";

		for (int d = 0; d < DIRECTIONS.size(); d++) {
			int newRow = now[0] + DIRECTIONS[d][0];
			int newCol = now[1] + DIRECTIONS[d][1];
			
			// 빈 곳이다
			if (newRow >= 1 && newRow <= R && newCol >= 1 && newCol <= C && graph[newRow][newCol] == '0') {

				//cout << "dp[" << newRow << "][" << newCol << "][" << now[2] << "] is : " << dp[newRow][newCol][now[2]] << ", dp[" << now[0] << "][" << now[1] << "][" << now[2] << "] + 1 is : " << dp[now[0]][now[1]][now[2]] + 1 << "\n";

				if (dp[newRow][newCol][now[2]] > dp[now[0]][now[1]][now[2]] + 1) {
					dp[newRow][newCol][now[2]] = dp[now[0]][now[1]][now[2]] + 1;
					int* next = new int[4];
					next[0] = newRow;
					next[1] = newCol;
					next[2] = now[2];
					next[3] = dp[newRow][newCol][now[2]];
					que.push(next);
				}
			}

			// 벽이다
			if (newRow >= 1 && newRow <= R && newCol >= 1 && newCol <= C && graph[newRow][newCol] == '1' && now[2] + 1 <= K) {

				//cout << "dp[" << newRow << "][" << newCol << "][" << now[2] << "] is : " << dp[newRow][newCol][now[2]] << ", dp[" << now[0] << "][" << now[1] << "][" << now[2] << "] + 1 is : " << dp[now[0]][now[1]][now[2]] + 1 << "\n";

				// 낮일 경우는 바로 돌파 가능
				if (dp[now[0]][now[1]][now[2]] % 2 == 1 && dp[newRow][newCol][now[2] + 1] > dp[now[0]][now[1]][now[2]] + 1) {
					dp[newRow][newCol][now[2] + 1] = dp[now[0]][now[1]][now[2]] + 1;
					int* next = new int[4];
					next[0] = newRow;
					next[1] = newCol;
					next[2] = now[2] + 1;
					next[3] = dp[newRow][newCol][now[2] + 1];
					que.push(next);
				}

				// 밤일 경우는 기다렸다가 돌파
				if (dp[now[0]][now[1]][now[2]] % 2 == 0 && dp[newRow][newCol][now[2] + 1] > dp[now[0]][now[1]][now[2]] + 2) {
					dp[newRow][newCol][now[2] + 1] = dp[now[0]][now[1]][now[2]] + 2;
					int* next = new int[4];
					next[0] = newRow;
					next[1] = newCol;
					next[2] = now[2] + 1;
					next[3] = dp[newRow][newCol][now[2] + 1];
					que.push(next);
				}
			}
		}
	}

	// 이렇게 했을 때 맨 마지막 위치의 최솟값을 찾으면 정답이 나옴
	int answer = 20000000;
	for (int i = 0; i <= K; i++) {
		answer = min(answer, dp[R][C][i]);
	}
	if (answer == 20000000) {
		cout << "-1";
	} else {
		cout << answer;
	}


	return 0;
}