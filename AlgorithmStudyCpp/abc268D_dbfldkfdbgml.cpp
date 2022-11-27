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
bool findAnswer;
unordered_set<string> B;
bool* visited;
int N, M;
string* A;
string* C;
string answer;
int totalLength;

void dfs(int now, string line, int cnt) {
	visited[now] = true;
	if (findAnswer) {
		return;
	}
	if (cnt == N) {
		if (B.find(line) == B.end()) {
			answer = line;
			findAnswer = true;
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			for (int j = 1; j <= (16 - totalLength) / N + 1; j++) {
				string next = line + C[j] + A[i];
				if (next.size() <= 16) {
					dfs(i, next, cnt + 1);
					visited[i] = false;
				}
			}
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	C = new string[17];
	C[0] = "";
	for (int i = 1; i <= 16; i++) {
		C[i] = C[i - 1] + "_";
	}

	cin >> N >> M;
	totalLength = 0;
	A = new string[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		totalLength += A[i].size();
	}
	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		B.insert(temp);
	}

	answer = "-1";
	findAnswer = false;
	visited = new bool[N];
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			dfs(i, A[i], 1);
			visited[i] = false;
		}
	}

	cout << answer;

	return 0;
}