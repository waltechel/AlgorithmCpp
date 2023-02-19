#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

/*
	시계방향을 표현하는 게 짜증나는 문제
*/

vector<vector<int>> direction = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int N;
	string S;

	cin >> N;
	cin >> S;

	pair<int, int> now = { 0, 0 };
	int dir = 0;// 0
	for (int i = 0; i < N; i++) {
		char c = S[i];
		if (c == 'S') {
			now.first += direction[dir][0];
			now.second += direction[dir][1];
		} else {
			dir += 1;
			dir %= 4;
		}
	}

	cout << now.second << " " << now.first;

	return 0;
}