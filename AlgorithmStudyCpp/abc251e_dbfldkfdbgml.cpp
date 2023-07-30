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

	int N;
	cin >> N;
	int* A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// 0번째를 뽑은 경우
	// 0번째를 뽑지 않은 경우 (맨 마지막을 반드시 뽑아야 하는 경우)
	// dp[i][j] = i번째를 j(0, 1)했을 경우 가장 적게 먹는 경우의 수
	const long long MAX = 1000000000000000000l;
	long long** dp = new long long* [N];
	for (int i = 0; i < N; i++) {
		dp[i] = new long long[2];
		for (int j = 0; j < 2; j++) {
			dp[i][j] = MAX;
		}
	}
	
	long long answer = MAX;
	dp[0][1] = A[0];
	for (int i = 1; i < N; i++) {
		if (dp[i - 1][0] != MAX) {//그 이전에 안 뽑았다면 이번에는 반드시 뽑아야 한다.
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + A[i]);
		}
		if (dp[i - 1][1] != MAX) {//그 이전에 뽑았다면 이번에는 뽑아도 되고 안 뽑아도 된다.
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + A[i]);
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		}
	}
	answer = min(min(answer, dp[N - 1][0]), dp[N - 1][1]);

	for (int i = 0; i < N; i++) {
		dp[i] = new long long[2];
		for (int j = 0; j < 2; j++) {
			dp[i][j] = MAX;
		}
	}
	dp[1][1] = A[1];
	for (int i = 2; i < N; i++) {
		if (dp[i - 1][0] != MAX) {//그 이전에 안 뽑았다면 이번에는 반드시 뽑아야 한다.
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + A[i]);
		}
		if (dp[i - 1][1] != MAX) {//그 이전에 뽑았다면 이번에는 뽑아도 되고 안 뽑아도 된다.
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + A[i]);
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		}
	}
	answer = min(answer, dp[N - 1][1]);

	cout << answer;
	return 0;
}