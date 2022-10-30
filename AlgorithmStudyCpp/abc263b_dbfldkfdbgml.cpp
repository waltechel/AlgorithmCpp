#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>

using namespace std;

// 가장 깊은 값이 아니라 N에서부터 시작하는 값
// editorial에서는 dp로 풀지만 여기서는 dfs로 수행
// The parent of Person i(2≤i≤N) is Person P
// Here, it is guaranteed that P
int main() {

	int N;
	cin >> N;

	int* parent = new int[N + 1];
	for (int i = 0; i <= N; i++) {
		parent[i] = 0;
	}

	parent[1] = 1;
	for (int i = 2; i <= N; i++) {
		cin >> parent[i];
	}

	int answer = 0;
	while (parent[N] != N) {
		N = parent[N];
		answer++;
	}
	
	cout << answer;

	return 0;
}

