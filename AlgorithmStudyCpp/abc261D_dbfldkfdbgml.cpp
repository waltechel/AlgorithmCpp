#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int* A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	long long answer = 0;

	for (int i = 1; i <= N; i++) {
		long long dp[101][101][101];
		for (int k = 0; k <= 100; k++) {
			for (int j = 0; j <= 100; j++) {
				for (int l = 0; l <= 100; l++) {
					dp[k][j][l] = 0;
				}
			}
		}

		dp[0][0][0] = 1;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k <= i; k++) {
				for (int l = 0; l < i; l++) {
					dp[j + 1][k][l] += dp[j][k][l];
					if (k != i) {
						dp[j + 1][k + 1][(l + a[j]) % i] += dp[j][k][l];
					}
				}
			}
		}
		answer += dp[N][i][0];
	}

	cout << answer << "";

	return 0;
}