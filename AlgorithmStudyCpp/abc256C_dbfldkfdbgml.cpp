#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

/*
  이게 브루트 포스가 된다는 것을 어떻게 증명할 수 있을까?
*/

int H[3];
int V[3];
int map[9];
int maxNum;
int answer;

bool isSafeH(int index, int n);
bool isSafeV(int index, int n);
void dfs(int index, int n);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 3; i++) {
		cin >> H[i];
	}

	for (int i = 0; i < 3; i++) {
		cin >> V[i];
	}

	for (int i = 0; i < 9; i++) {
		map[i] = 0;
	}

	maxNum = -1;
	for (int i = 0; i < 3; i++) {
		maxNum = max(maxNum, H[i]);
	}
	for (int i = 0; i < 3; i++) {
		maxNum = max(maxNum, V[i]);
	}
	maxNum += 2;

	answer = 0;
	for (int i = 1; i <= maxNum - 2; i++) {
		if (isSafeH(0, i)) {
			if (isSafeV(0, i)) {
				dfs(0, i);
				map[0] = 0;
			}
		}
	}

	cout << answer;

	return 0;
}

void dfs(int index, int n) {
	map[index] = n;

	if (index == 8) {
		answer++;
		return;
	}

	for (int i = 1; i <= maxNum - 2; i++) {
		if (isSafeH(index + 1, i)) {
			if (isSafeV(index + 1, i)) {
				dfs(index + 1, i);
				map[index + 1] = 0;
			}
		}
	}
}

bool isSafeH(int index, int n) {
	map[index] = n;
	if (index >= 2) {
		if (map[0] + map[1] + map[2] != H[0]) {
			map[index] = 0;
			return false;
		}
	}
	if (index >= 5) {
		if (map[3] + map[4] + map[5] != H[1]) {
			map[index] = 0;
			return false;
		}
	}
	if (index >= 8) {
		if (map[6] + map[7] + map[8] != H[2]) {
			map[index] = 0;
			return false;
		}
	}
	map[index] = 0;
	return true;
}

bool isSafeV(int index, int n) {
	map[index] = n;
	if (index >= 6) {
		if (map[0] + map[3] + map[6] != V[0]) {
			map[index] = 0;
			return false;
		}
	}
	if (index >= 7) {
		if (map[1] + map[4] + map[7] != V[1]) {
			map[index] = 0;
			return false;
		}
	}
	if (index >= 8) {
		if (map[2] + map[5] + map[8] != V[2]) {
			map[index] = 0;
			return false;
		}
	}
	map[index] = 0;
	return true;
}
