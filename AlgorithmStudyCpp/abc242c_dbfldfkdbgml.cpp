#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dp[1000001][10];

/*
	반드시 int 범위 안에 풀리는 dp 문제
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	
	const int MOD = 998244353;

	for (int i = 2; i <= 1000000; i++) {
		if (int j = 1) {
			dp[i][j] += dp[i - 1][1];
			dp[i][j] %= MOD;
			dp[i][j] += dp[i - 1][2];
			dp[i][j] %= MOD;
		}
		for (int j = 2; j <= 8; j++) {
			dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] %= MOD;
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= MOD;
			dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= MOD;
		}
		if (int j = 9) {
			dp[i][j] += dp[i - 1][9];
			dp[i][j] %= MOD;
			dp[i][j] += dp[i - 1][8];
			dp[i][j] %= MOD;
		}
	}

	int N;
	cin >> N;
	int answer = 0;
	for (int i = 1; i <= 9; i++) {
		answer += dp[N][i];
		answer %= MOD;
	}
	cout << answer;

	return 0;
}