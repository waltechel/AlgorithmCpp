#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>

using namespace std;

int N, M;
int A[11];

void dfs(int depth, int value);

// 가장 깊은 값이 아니라 N에서부터 시작하는 값
// editorial에서는 dp로 풀지만 여기서는 dfs로 수행
int main() {

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		dfs(1, i);
	}

	return 0;
}

void dfs(int depth, int value) {

	A[depth] = value;

	if (depth == N) {
		for (int i = 1; i <= N; i++) {
			cout << A[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = value + 1; i <= M; i++) {
		dfs(depth + 1, i);
	}

}
