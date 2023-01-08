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

bool** graph;

void dfs(int fromRow, int fromCol, int T, bool flag) {

	if (T == 1) {
		graph[fromRow][fromCol] = flag;
		return;
	}

	if (flag == false) {
		for (int i = fromCol; i < fromCol + T; i++) {
			for (int j = fromRow; j < fromRow + T; j++) {
				graph[i][j] = false;
			}
		}
		return;
	}

	dfs(fromRow, fromCol, T / 3, true);
	dfs(fromRow, fromCol + T / 3, T / 3, true);
	dfs(fromRow, fromCol + T / 3 + T / 3, T / 3, true);
	dfs(fromRow + T / 3, fromCol, T / 3, true);
	dfs(fromRow + T / 3, fromCol + T / 3, T / 3, false);
	dfs(fromRow + T / 3, fromCol + T / 3 + T / 3, T / 3, true);
	dfs(fromRow + T / 3 + T / 3, fromCol, T / 3, true);
	dfs(fromRow + T / 3 + T / 3, fromCol + T / 3, T / 3, true);
	dfs(fromRow + T / 3 + T / 3, fromCol + T / 3 + T / 3, T / 3, true);
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	graph = new bool*[T + 1];
	for (int i = 0; i <= T; i++) {
		graph[i] = new bool[T + 1];
		for (int j = 0; j <= T; j++) {
			graph[i][j] = false;
		}
	}

	dfs(1, 1, T / 3, true);
	dfs(1, 1 + T / 3, T / 3, true);
	dfs(1, 1 + T / 3 + T / 3, T / 3, true);
	dfs(1 + T / 3, 1, T / 3, true);
	dfs(1 + T / 3, 1 + T / 3, T / 3, false);
	dfs(1 + T / 3, 1 + T / 3 + T / 3, T / 3, true);
	dfs(1 + T / 3 + T / 3, 1, T / 3, true);
	dfs(1 + T / 3 + T / 3, 1 + T / 3, T / 3, true);
	dfs(1 + T / 3 + T / 3, 1 + T / 3 + T / 3, T / 3, true);

	for (int i = 1; i <= T; i++) {
		for (int j = 1; j <= T; j++) {
			if (graph[i][j]) {
				cout << "*";
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}


	return 0;
}