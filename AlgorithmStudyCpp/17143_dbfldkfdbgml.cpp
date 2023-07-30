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

// 크기, 방향, 속력
int graph[101][101][5];
vector<vector<int>> DIRECTIONS = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} }; // 위 아래 오른쪽 왼쪽

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int R, C, M;
	cin >> R >> C >> M;
	vector<int*> sharksA;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		// 상어의 row, col, 속력, 이동 방향, 크기
		cin >> r >> c >> s >> d >> z;
		int* temp = new int[5];
		temp[0] = r;
		temp[1] = c;
		temp[2] = s;
		temp[3] = d - 1;
		temp[4] = z;
		sharksA.push_back(temp);
	}

	int answer = 0;
	// 낚시왕이 오른쪽으로 한칸 이동한다
	for (int column = 1; column <= C; column++) {
		// 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 
		// 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
		for (int a = 0; a <= 100; a++) {
			for (int b = 0; b <= 100; b++) {
				for (int c = 0; c < 3; c++) {
					graph[a][b][c] = 0;
				}
			}
		}
		for (int* shark : sharksA) {
			graph[shark[0]][shark[1]][0] = shark[2];
			graph[shark[0]][shark[1]][1] = shark[3];
			graph[shark[0]][shark[1]][2] = shark[4];
		}
		for (int row = 1; row <= R; row++) {
			if (graph[row][column][2] != 0) { // 크기가 0인 경우는 없다
				answer += graph[row][column][2];
				graph[row][column][0] = 0;
				graph[row][column][1] = 0;
				graph[row][column][2] = 0;
				break;
			}
		}

		vector<int*> sharksB;
		// 상어가 이동한다
		for (int a = 0; a <= 100; a++) {
			for (int b = 0; b <= 100; b++) {
				if (graph[a][b][2] != 0) {// 크기가 0인 경우는 없다
					int* temp = new int[5];
					temp[0] = a;
					temp[1] = b;
					temp[2] = graph[a][b][0];
					temp[3] = graph[a][b][1];
					temp[4] = graph[a][b][2];
					sharksB.push_back(temp);
				}
			}
		}

		// 모듈러 연산을 이용하면 상어의 이동을 줄일 수 있다!
		for (int* shark : sharksB) {
			// 행이나 열
			int repeat = 0;
			if (shark[3] == 0 || shark[3] == 1){ // 위 아래 일 때
				repeat = shark[2] % ((R - 1) * 2);
			}
			if (shark[3] == 2 || shark[3] == 3) { // 왼쪽 오른쪽일 때
				repeat = shark[2] % ((C - 1) * 2);
			}
			// repeat 만큼 반복한 다음 위치를 수정한다
			int newRow = shark[0];
			int newCol = shark[1];
			int newSpeed = shark[2];
			int newDirection = shark[3];
			int newZill = shark[4];
			for (int i = 0; i < repeat; i++) {
				newRow = newRow + DIRECTIONS[newDirection][0];
				newCol = newCol + DIRECTIONS[newDirection][1];
				if (newDirection == 0 && newRow == 1) {
					newDirection = 1;
				}
				if (newDirection == 1 && newRow == R) {
					newDirection = 0;
				}
				if (newDirection == 2 && newCol == C) {
					newDirection = 3;
				}
				if (newDirection == 3 && newCol == 1) {
					newDirection = 2;
				}
			}
			shark[0] = newRow;
			shark[1] = newCol;
			shark[2] = newSpeed;
			shark[3] = newDirection;
			shark[4] = newZill;
		}

		for (int a = 0; a <= 100; a++) {
			for (int b = 0; b <= 100; b++) {
				for (int c = 0; c < 3; c++) {
					graph[a][b][c] = 0;
				}
			}
		}
		for (int* shark : sharksB) {
			if (graph[shark[0]][shark[1]][2] < shark[4]) {
				graph[shark[0]][shark[1]][0] = shark[2];
				graph[shark[0]][shark[1]][1] = shark[3];
				graph[shark[0]][shark[1]][2] = shark[4];
			}
		}
		sharksA.clear();
		for (int a = 0; a <= 100; a++) {
			for (int b = 0; b <= 100; b++) {
				if (graph[a][b][2] != 0) {// 크기가 0인 경우는 없다
					int* temp = new int[5];
					temp[0] = a;
					temp[1] = b;
					temp[2] = graph[a][b][0];
					temp[3] = graph[a][b][1];
					temp[4] = graph[a][b][2];
					sharksA.push_back(temp);
				}
			}
		}

	}

	cout << answer;

	
	return 0;
}