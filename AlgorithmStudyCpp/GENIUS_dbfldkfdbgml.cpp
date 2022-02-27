#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int L[50];
double dp[10][50][2];
double T[50][50];

int main() {

	cout << fixed;
	cout.precision(10);

	int TEST;
	cin >> TEST;
	for (int test = 0; test < TEST; test++) {
		int N, K, M;
		cin >> N >> K >> M;

		for (int i = 0; i < N; i++) {
			cin >> L[i];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> T[i][j];
			}
		}

		// 공간최적화 필요
		// dp 배열[K][N][2] : K분대일 때 N번 노래가 마지막인가 아닌가
		// 10분 안에는 대충 한번 순환된다.
		int MOD = 10;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 50; j++) {
				for (int k = 0; k < 2; k++) {
					dp[i][j][k] = 0.0;
				}
			}
		}
		for (int i = 0; i < L[0] - 1; i++) {
			dp[i % MOD][0][0] = 1.0;
		}
		dp[(L[0] - 1) % MOD][0][1] = 1.0;
		for (int i = 0; i <= K; i++) {
			for (int from = 0; from < N; from++) {
				if (dp[i % MOD][from][1] > 0) {
					for (int to = 0; to < N; to++) {
						for (int nextLength = 1; nextLength < L[to]; nextLength++) {
							if (i + nextLength <= K) {
								dp[(i + nextLength) % MOD][to][0] += dp[i % MOD][from][1] * T[from][to];
							}
						}
						if (i + L[to] <= K) {
							dp[(i + L[to]) % MOD][to][1] += dp[i % MOD][from][1] * T[from][to];
						}
					}
				}
				dp[(i + MOD - 1) % MOD][from][0] = 0.0;
				dp[(i + MOD - 1) % MOD][from][1] = 0.0;
			}
		}
		int index;
		for (int i = 0; i < M; i++) {
			cin >> index;
			cout << (dp[K % MOD][index][0] + dp[K % MOD][index][1]) <<  " ";
		}
		cout << "\n";
	}
	return 0;
}