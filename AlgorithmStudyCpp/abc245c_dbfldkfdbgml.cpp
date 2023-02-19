#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

// dp 문제로 풀리는 것 같다.

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int N, K;
	cin >> N >> K;
	vector<int> A(N, 0);
	vector<int> B(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	vector<vector<bool>> dp(N, vector<bool>(2, false));
	dp[0][0] = true;
	dp[0][1] = true;
	for (int i = 1; i < N; i++) {
		if (dp[i - 1][0] && abs(A[i] - A[i - 1]) <= K) {
			dp[i][0] = true;
		}
		if (dp[i - 1][1] && abs(A[i] - B[i - 1]) <= K) {
			dp[i][0] = true;
		}
		if (dp[i - 1][0] && abs(B[i] - A[i - 1]) <= K) {
			dp[i][1] = true;
		}
		// 여기서 괄호를 제대로 못 써서 틀렸다 ㅠㅠ
		if (dp[i - 1][1] && abs(B[i] - B[i - 1]) <= K) {
			dp[i][1] = true;
		}
	}

	if (dp[N - 1][0] || dp[N - 1][1]) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}