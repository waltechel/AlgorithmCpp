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

/*
	판데기까지 넣어서 BFS 탐색하는 문제
	파란 게 따라 나와도 실패 
*/
// 왼쪽으로 이동, 오른쪽으로 이동, 아래로 이동, 위로 이동
vector<vector<int>> DIRECTIONS = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int R, C;
	cin >> R >> C;
	char** map = new char*[R];
	for (int i = 0; i < R; i++) {
		map[i] = new char[C];
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	int endRow = -1;
	int endCol = -1;
	int point = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'R') {
				point += i * 1000;
				point += j * 100;
				map[i][j] = '.';
			}
			if (map[i][j] == 'B') {
				point += i * 10;
				point += j;
				map[i][j] = '.';
			}
			if (map[i][j] == 'O') {
				endRow = i;
				endCol = j;
				map[i][j] = '.';
			}
		}
	}

	bool findAnswer = false;
	unordered_set<int> visited;
	queue<pair<int, int>> que;
	que.push({ point, 0 });
	visited.insert(point);
	while (!que.empty()) {
		int now = que.front().first;
		int depth = que.front().second;
		que.pop();
		int redRow = now / 1000;
		int redCol = now % 1000 / 100;
		int blueRow = now % 100 / 10;
		int blueCol = now % 10;

		/*
			왼쪽으로 이동
		*/
		int lstRedRow = redRow;
		int lstRedCol = redCol;
		int lstBlueRow = blueRow;
		int lstBlueCol = blueCol;

		bool redOut = false;
		bool blueOut = false;
		// 왼쪽으로 이동
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (i == redRow && j == redCol) {
					for (int k = 1; k <= 10; k++) { // 왼쪽으로 갈 수 있는 만큼 이동함
						int newRedRow = redRow + DIRECTIONS[0][0] * k;
						int newRedCol = redCol + DIRECTIONS[0][1] * k;
						// 갈 수 있는 곳이고 공하고도 안 부딪침
						if (newRedRow >= 0 && newRedRow < R && newRedCol >= 0 && newRedCol < C && map[newRedRow][newRedCol] == '.'
							&& (newRedRow != lstBlueRow || newRedCol != lstBlueCol)) {
							lstRedRow = newRedRow;
							lstRedCol = newRedCol;
						} else {
							break;
						}

						if (newRedRow >= 0 && newRedRow < R && newRedCol >= 0 && newRedCol < C && map[newRedRow][newRedCol] == '.'
							&& (newRedRow == endRow && newRedCol == endCol)) {
							redOut = true;
						}


					}
				}
				if (i == blueRow && j == blueCol) {
					for (int k = 1; k <= 10; k++) {
						int newBlueRow = blueRow + DIRECTIONS[0][0] * k;
						int newBlueCol = blueCol + DIRECTIONS[0][1] * k;
						if (newBlueRow >= 0 && newBlueRow < R && newBlueCol >= 0 && newBlueCol < C && map[newBlueRow][newBlueCol] == '.'
							&& (newBlueRow != lstRedRow || newBlueCol != lstRedCol)) {
							lstBlueRow = newBlueRow;
							lstBlueCol = newBlueCol;
						} else {
							break;
						}
						if (newBlueRow >= 0 && newBlueRow < R && newBlueCol >= 0 && newBlueCol < C && map[newBlueRow][newBlueCol] == '.'
							&& (newBlueRow == endRow && newBlueCol == endCol)) {
							lstBlueRow = newBlueRow;
							lstBlueCol = newBlueCol;
							blueOut = true;
						}
					}
				}
			}
		}
		int next = lstRedRow * 1000 + lstRedCol * 100 + lstBlueRow * 10 + lstBlueCol;
		if (redOut == false && blueOut == false && visited.find(next) == visited.end() && depth + 1 <= 10) {
			visited.insert(next);
			que.push({ next, depth + 1 });
		}
		if (redOut == true && blueOut == false) {
			findAnswer = true;
			break;
		}

		/*
			오른쪽으로 이동
		*/
		lstRedRow = redRow;
		lstRedCol = redCol;
		lstBlueRow = blueRow;
		lstBlueCol = blueCol;

		redOut = false;
		blueOut = false;
		// 오른쪽으로 이동
		for (int i = 0; i < R; i++) {
			for (int j = C - 1; j >= 0; j--) {
				if (i == redRow && j == redCol) {
					for (int k = 1; k <= 10; k++) { // 오른쪽으로 갈 수 있는 만큼 이동함
						int newRedRow = redRow + DIRECTIONS[1][0] * k;
						int newRedCol = redCol + DIRECTIONS[1][1] * k;
						// 갈 수 있는 곳이고 공하고도 안 부딪침
						if (newRedRow >= 0 && newRedRow < R && newRedCol >= 0 && newRedCol < C && map[newRedRow][newRedCol] == '.'
							&& (newRedRow != lstBlueRow || newRedCol != lstBlueCol)) {
							lstRedRow = newRedRow;
							lstRedCol = newRedCol;
						} else {
							break;
						}

						if (newRedRow >= 0 && newRedRow < R && newRedCol >= 0 && newRedCol < C && map[newRedRow][newRedCol] == '.'
							&& (newRedRow == endRow && newRedCol == endCol)) {
							redOut = true;
						}
					}
				}
				if (i == blueRow && j == blueCol) {
					for (int k = 1; k <= 10; k++) {
						int newBlueRow = blueRow + DIRECTIONS[1][0] * k;
						int newBlueCol = blueCol + DIRECTIONS[1][1] * k;
						if (newBlueRow >= 0 && newBlueRow < R && newBlueCol >= 0 && newBlueCol < C && map[newBlueRow][newBlueCol] == '.'
							&& (newBlueRow != lstRedRow || newBlueCol != lstRedCol)) {
							lstBlueRow = newBlueRow;
							lstBlueCol = newBlueCol;
						} else {
							break;
						}
						if (newBlueRow >= 0 && newBlueRow < R && newBlueCol >= 0 && newBlueCol < C && map[newBlueRow][newBlueCol] == '.'
							&& (newBlueRow == endRow && newBlueCol == endCol)) {
							lstBlueRow = newBlueRow;
							lstBlueCol = newBlueCol;
							blueOut = true;
						}
					}
				}
			}
		}
		next = lstRedRow * 1000 + lstRedCol * 100 + lstBlueRow * 10 + lstBlueCol;
		if (redOut == false && blueOut == false && visited.find(next) == visited.end() && depth + 1 <= 10) {
			visited.insert(next);
			que.push({ next, depth + 1 });
		}
		if (redOut == true && blueOut == false) {
			findAnswer = true;
			break;
		}


		/*
			아래쪽으로 이동
		*/
		lstRedRow = redRow;
		lstRedCol = redCol;
		lstBlueRow = blueRow;
		lstBlueCol = blueCol;

		redOut = false;
		blueOut = false;
		// 아래쪽으로 이동
		for (int i = 0; i < R; i++) {
			for (int j = C - 1; j >= 0; j--) {
				if (i == redRow && j == redCol) {
					for (int k = 1; k <= 10; k++) { // 아래쪽으로 갈 수 있는 만큼 이동함
						int newRedRow = redRow + DIRECTIONS[2][0] * k;
						int newRedCol = redCol + DIRECTIONS[2][1] * k;
						// 갈 수 있는 곳이고 공하고도 안 부딪침
						if (newRedRow >= 0 && newRedRow < R && newRedCol >= 0 && newRedCol < C && map[newRedRow][newRedCol] == '.'
							&& (newRedRow != lstBlueRow || newRedCol != lstBlueCol)) {
							lstRedRow = newRedRow;
							lstRedCol = newRedCol;
						} else {
							break;
						}

						if (newRedRow >= 0 && newRedRow < R && newRedCol >= 0 && newRedCol < C && map[newRedRow][newRedCol] == '.'
							&& (newRedRow == endRow && newRedCol == endCol)) {
							redOut = true;
						}
					}
				}
				if (i == blueRow && j == blueCol) {
					for (int k = 1; k <= 10; k++) {
						int newBlueRow = blueRow + DIRECTIONS[2][0] * k;
						int newBlueCol = blueCol + DIRECTIONS[2][1] * k;
						if (newBlueRow >= 0 && newBlueRow < R && newBlueCol >= 0 && newBlueCol < C && map[newBlueRow][newBlueCol] == '.'
							&& (newBlueRow != lstRedRow || newBlueCol != lstRedCol)) {
							lstBlueRow = newBlueRow;
							lstBlueCol = newBlueCol;
						} else {
							break;
						}
						if (newBlueRow >= 0 && newBlueRow < R && newBlueCol >= 0 && newBlueCol < C && map[newBlueRow][newBlueCol] == '.'
							&& (newBlueRow == endRow && newBlueCol == endCol)) {
							lstBlueRow = newBlueRow;
							lstBlueCol = newBlueCol;
							blueOut = true;
						}
					}
				}
			}
		}
		next = lstRedRow * 1000 + lstRedCol * 100 + lstBlueRow * 10 + lstBlueCol;
		if (redOut == false && blueOut == false && visited.find(next) == visited.end() && depth + 1 <= 10) {
			visited.insert(next);
			que.push({ next, depth + 1 });
		}
		if (redOut == true && blueOut == false) {
			findAnswer = true;
			break;
		}


		/*
			위쪽으로 이동
		*/
		lstRedRow = redRow;
		lstRedCol = redCol;
		lstBlueRow = blueRow;
		lstBlueCol = blueCol;

		redOut = false;
		blueOut = false;
		// 위쪽으로 이동
		for (int i = R - 1; i >= 0; i--) {
			for (int j = C - 1; j >= 0; j--) {
				if (i == redRow && j == redCol) {
					for (int k = 1; k <= 10; k++) { // 위쪽으로 갈 수 있는 만큼 이동함
						int newRedRow = redRow + DIRECTIONS[3][0] * k;
						int newRedCol = redCol + DIRECTIONS[3][1] * k;
						// 갈 수 있는 곳이고 공하고도 안 부딪침
						if (newRedRow >= 0 && newRedRow < R && newRedCol >= 0 && newRedCol < C && map[newRedRow][newRedCol] == '.'
							&& (newRedRow != lstBlueRow || newRedCol != lstBlueCol)) {
							lstRedRow = newRedRow;
							lstRedCol = newRedCol;
						} else {
							break;
						}

						if (newRedRow >= 0 && newRedRow < R && newRedCol >= 0 && newRedCol < C && map[newRedRow][newRedCol] == '.'
							&& (newRedRow == endRow && newRedCol == endCol)) {
							redOut = true;
						}
					}
				}
				if (i == blueRow && j == blueCol) {
					for (int k = 1; k <= 10; k++) {
						int newBlueRow = blueRow + DIRECTIONS[3][0] * k;
						int newBlueCol = blueCol + DIRECTIONS[3][1] * k;
						if (newBlueRow >= 0 && newBlueRow < R && newBlueCol >= 0 && newBlueCol < C && map[newBlueRow][newBlueCol] == '.'
							&& (newBlueRow != lstRedRow || newBlueCol != lstRedCol)) {
							lstBlueRow = newBlueRow;
							lstBlueCol = newBlueCol;
						} else {
							break;
						}
						if (newBlueRow >= 0 && newBlueRow < R && newBlueCol >= 0 && newBlueCol < C && map[newBlueRow][newBlueCol] == '.'
							&& (newBlueRow == endRow && newBlueCol == endCol)) {
							lstBlueRow = newBlueRow;
							lstBlueCol = newBlueCol;
							blueOut = true;
						}
					}
				}
			}
		}
		next = lstRedRow * 1000 + lstRedCol * 100 + lstBlueRow * 10 + lstBlueCol;
		if (redOut == false && blueOut == false && visited.find(next) == visited.end() && depth + 1 <= 10) {
			visited.insert(next);
			que.push({ next, depth + 1 });
		}
		if (redOut == true && blueOut == false) {
			findAnswer = true;
			break;
		}

	}


	if (findAnswer) {
		cout << "1";
	} else {
		cout << "0";
	}


    return 0;

}