#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_set>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(0);

	int R, C;
	cin >> R >> C;
	char map[100][100];
	int dist[100][100];
	for (int i = 0; i < R; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < C; j++) {
			map[i][j] = line[j];
			dist[i][j] = 500;
		}
	}

	int start_row = -1, start_col = -1;
	int end_row = -1, end_col = -1;
	bool first = true;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'o' && first) {
				start_row = i;
				start_col = j;
				first = false;
				continue;
			}
			if (map[i][j] == 'o' && !first) {
				end_row = i;
				end_col = j;
				continue;
			}
		}
	}
	//cout << start_row << " " << start_col << "\n";
	//cout << end_row << " " << end_col << "\n";
	
	int answer = abs(start_row - end_row) + abs(start_col - end_col);
	cout << answer;

	return 0;
}