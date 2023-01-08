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
#include<regex>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 사이즈를 줄일 수 있는 부분이니 참고 바람
	bool dp[101][10001];
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 10000; j++) {
			dp[i][j] = false;
		}
	}
	dp[0][0] = true;
	int N, X;
	cin >> N >> X;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 0; j <= 10000; j++) {
			if (dp[i - 1][j]) {
				if (j + a <= 10000) {
					dp[i][j + a] = true;
				}
				if (j + b <= 10000) {
					dp[i][j + b] = true;
				}
			}
		}
	}

	if (dp[N][X]) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}