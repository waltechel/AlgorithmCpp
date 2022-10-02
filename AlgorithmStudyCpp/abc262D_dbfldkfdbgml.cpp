#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;
long long dp[101][101][101];

int main() {

	const int MOD = 998244353;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int* A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// dp[j][k][l] : j까지의 배열 중 k개를 선택을 때 i로 나눈 나머지가 l인 경우의 수
	// 단 j번째의 수를 선택하여야 한다.
	long long answer = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 100; j++) {
			for (int k = 0; k <= 100; k++) {
				for (int l = 0; l <= 100; l++) {
					dp[j][k][l] = 0;
				}
			}
		}

		dp[0][0][0] = 1;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k <= i; k++) {
				for (int l = 0; l < i; l++) {
					//j번째를 선택하지 않았으므로 그대로 계승
					dp[j + 1][k][l] += dp[j][k][l];
					dp[j + 1][k][l] %= MOD;
					//i
					if (k != i) {
						dp[j + 1][k + 1][(l + A[j]) % i] += dp[j][k][l];
						dp[j + 1][k + 1][(l + A[j]) % i] %= MOD;
					}
				}
			}
		}
		answer += dp[N][i][0];
		answer %= MOD;
	}

	cout << answer % MOD << "";

	return 0;
}