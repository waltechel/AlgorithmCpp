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

using namespace std;

long long max(long long a, long long b, long long c);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int* T = new int[N];
	int* X = new int[N];
	int* A = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> T[i] >> X[i] >> A[i];
	}

	long long** dp = new long long* [100001];
	for (int i = 0; i <= 100000; i++) {
		dp[i] = new long long[5];
		for (int j = 0; j <= 4; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		int Ti = T[i];
		int Xi = X[i];
		int Ai = A[i];
		dp[Ti][Xi] = Ai;
	}
	dp[0][1] = -1;
	dp[0][2] = -1;
	dp[0][3] = -1;
	dp[0][4] = -1;

	for (int i = 1; i <= 100000; i++) {

		if (max(dp[i - 1][0], dp[i - 1][1]) != -1) {
			dp[i][0] += max(dp[i - 1][0], dp[i - 1][1]);
		} else {
			dp[i][0] = -1;
		}
		if (max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) != -1) {
			dp[i][1] += max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
		} else {
			dp[i][0] = -1;
		}
		if (max(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]) != -1) {
			dp[i][2] += max(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]);
		} else {
			dp[i][2] = -1;
		}
		if (max(dp[i - 1][2], dp[i - 1][3], dp[i - 1][4]) != -1) {
			dp[i][3] += max(dp[i - 1][2], dp[i - 1][3], dp[i - 1][4]);
		} else {
			dp[i][3] = -1;
		}
		if (max(dp[i - 1][3], dp[i - 1][4]) != -1) {
			dp[i][4] += max(dp[i - 1][3], dp[i - 1][4]);
		} else {
			dp[i][4] = -1;
		}

	}

	long long answer = 0;
	for (int i = 0; i <= 4; i++) {
		answer = max(answer, dp[100000][i]);
	}
	cout << answer;

	return 0;
}

long long max(long long a, long long b, long long c) {
	return max(max(a, b), c);
}