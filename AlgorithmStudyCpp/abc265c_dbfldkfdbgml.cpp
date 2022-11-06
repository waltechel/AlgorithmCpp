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

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int H, W;
	cin >> H >> W;

	char** graph = new char* [H + 1];
	for (int i = 1; i <= H; i++) {
		graph[i] = new char[W];
		for (int j = 1; j <= W; j++) {
			cin >> graph[i][j];
		}
	}

	bool** visited = new bool* [H + 1];
	for (int i = 1; i <= H; i++) {
		visited[i] = new bool[W]();
	}

	queue<int*> que;
	que.push(new int[] {1, 1});

	bool isCycle = false;
	int answerRow = -1;
	int answerCol = -1;
	while (!que.empty()) {
		int* now = que.front();
		que.pop();
		visited[now[0]][now[1]] = true;
		char direction = graph[now[0]][now[1]];
		int* next;
		if (direction == 'R') {
			next = new int[] {now[0] + 0, now[1] + 1};
		} else if (direction == 'L') {
			next = new int[] {now[0] + 0, now[1] - 1};
		} else if (direction == 'U') {
			next = new int[] {now[0] - 1, now[1] + 0};
		} else if (direction == 'D') {
			next = new int[] {now[0] + 1, now[1] + 0};
		}
		if (1 <= next[0] && next[0] <= H && 1 <= next[1] && next[1] <= W) {
			if (visited[next[0]][next[1]]) {
				isCycle = true;
				break;
			} else {
				que.push(new int[] {next[0], next[1]});
			}
		} else {
			answerRow = now[0];
			answerCol = now[1];
			break;
		}
		delete now;
	}

	if (isCycle) {
		cout << "-1";
	} else {
		cout << answerRow << " " << answerCol;
	}

	return 0;
}