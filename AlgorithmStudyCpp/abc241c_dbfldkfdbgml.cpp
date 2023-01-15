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

int getCountofBlackByPoint(string* map, int row, int col) {
	if (map[row][col] == '#') {
		return 1;
	} else {
		return 0;
	}
}

int getCountofBlack(string* map, int row, int col, int direction) {
	int ret = 0;
	if (direction == 0) { // 가로로 쭉 나열
		ret += getCountofBlackByPoint(map, row, col);
		ret += getCountofBlackByPoint(map, row, col + 1);
		ret += getCountofBlackByPoint(map, row, col + 2);
		ret += getCountofBlackByPoint(map, row, col + 3);
		ret += getCountofBlackByPoint(map, row, col + 4);
		ret += getCountofBlackByPoint(map, row, col + 5);
	} else if (direction == 1) { // 세로로 쭉 나열
		ret += getCountofBlackByPoint(map, row, col);
		ret += getCountofBlackByPoint(map, row + 1, col);
		ret += getCountofBlackByPoint(map, row + 2, col);
		ret += getCountofBlackByPoint(map, row + 3, col);
		ret += getCountofBlackByPoint(map, row + 4, col);
		ret += getCountofBlackByPoint(map, row + 5, col);
	} else if (direction == 2) { // 우하 대각선으로 쭉 나열
		ret += getCountofBlackByPoint(map, row, col);
		ret += getCountofBlackByPoint(map, row + 1, col + 1);
		ret += getCountofBlackByPoint(map, row + 2, col + 2);
		ret += getCountofBlackByPoint(map, row + 3, col + 3);
		ret += getCountofBlackByPoint(map, row + 4, col + 4);
		ret += getCountofBlackByPoint(map, row + 5, col + 5);
	} else if (direction == 3) { // 좌하 대각선으로 나열
		ret += getCountofBlackByPoint(map, row, col);
		ret += getCountofBlackByPoint(map, row + 1, col - 1);
		ret += getCountofBlackByPoint(map, row + 2, col - 2);
		ret += getCountofBlackByPoint(map, row + 3, col - 3);
		ret += getCountofBlackByPoint(map, row + 4, col - 4);
		ret += getCountofBlackByPoint(map, row + 5, col - 5);
	}
	return ret;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	string* map = new string[N];
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	bool flag = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < N && j < N - 5 && getCountofBlack(map, i, j, 0) >= 4) {
				flag = true;
			}
			if (i < N - 5 && j < N && getCountofBlack(map, i, j, 1) >= 4) {
				flag = true;
			}
			if (i < N - 5 && j < N - 5 && getCountofBlack(map, i, j, 2) >= 4) {
				flag = true;
			}
			if (i < N - 5 && 5 <= j && getCountofBlack(map, i, j, 3) >= 4) {
				flag = true;
			}
		}
	}

	if (flag) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}