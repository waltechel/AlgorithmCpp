#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_set>
#include <set>

/*
	어디가 틀렸음
*/
using namespace std;

long long dp[1001][5001];
long long dp1[1001][5001];
long long dp2[1001][5001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long N;
	int M, K;
	
	cin >> N;
	cin >> M >> K;

	const long long MOD = 998244353;
	// 초항
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= M; j++) {
			if (j + K <= M) {
				if (i == 1) {
					dp1[i + 1][j + K]++;
				} else {
					dp1[i + 1][j + K] += dp1[i][j] + dp2[i][j];
				}
				dp1[i + 1][j + K] %= MOD;
			}
			if (j - K >= 1) {
				if (i == 1) {
					dp2[i + 1][j - K]++;
				} else {
					dp2[i + 1][j - K] += dp1[i][j] + dp2[i][j];
				}
				dp2[i + 1][j - K] %= MOD;
			}
		}
		for (int j = 1; j + 1 <= M; j++) {
			dp1[i + 1][j + 1] += dp1[i + 1][j];
			dp1[i + 1][j + 1] %= MOD;
		}
		for (int j = M; j - 1 >= 1; j--) {
			dp2[i + 1][j - 1] += dp2[i + 1][j];
			dp2[i + 1][j - 1] %= MOD;
		}
	/*	for (int j = 1; j <= M; j++) {
			long long tmp = dp1[i + 1][j] + dp2[i + 1][j];
			dp1[i + 1][j] = tmp;
			dp2[i + 1][j] = tmp;
		}*/
	}

	cout << "==========================\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << dp1[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "==========================\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << dp2[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "==========================\n";
	// 
	long long answer = 0;
	for (int j = 1; j <= M; j++) {
		answer += dp1[N][j];
		answer += dp2[N][j];
		answer %= MOD;
	}
	cout << answer;
	
	return 0;
}