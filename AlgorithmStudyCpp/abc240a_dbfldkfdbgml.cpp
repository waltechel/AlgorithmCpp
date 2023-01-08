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

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool** graph = new bool* [11];
	for (int i = 0; i <= 10; i++) {
		graph[i] = new bool[11];
		for (int j = 0; j <= 10; j++) {
			graph[i][j] = false;
		}
	}

	graph[1][10] = true;
	graph[10][1] = true;

	for (int i = 1; i <= 9; i++) {
		graph[i][i + 1] = true;
		graph[i + 1][i] = true;
	}

	int a, b;
	cin >> a >> b;
	
	if (graph[a][b]) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}