#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
	이거 순서가 바뀌면 틀리는데 왜 그런가요?
*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int N;
		cin >> N;
		vector<int> list(N);
		for (int i = 0; i < N; i++) {
			cin >> list[i];
		}
		int M;
		cin >> M;
		vector<int> dp(M + 1);
		dp[0] = 1;
		for (int j = 0; j < N; j++) {
			for (int i = 1; i <= M; i++) {
				if (i - list[j] >= 0)
					dp[i] += dp[i - list[j]];
			}
		}

		/* 이렇게 하면 답이 다르게 나옵니다.
		for (int i = 1; i <= M; i++) {
			for (int j = 0; j < N; j++) {
				if (i - list[j] >= 0)
					dp[i] += dp[i - list[j]];
			}
		}
		*/
		cout << dp[M] << "\n";
	}

	return 0;
}