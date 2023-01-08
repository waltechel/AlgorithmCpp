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

// 단순히 많이 먹어서는 좋지 않다.
// DP[n] = the number of stones that the first player can take if the game starts with a pile with n stones.

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	int* dp;

	cin >> N >> K;
	dp = new int[N + 1];
	for (int i = 0; i <= N; i++) {
		dp[i] = 0;
	}
	vector<int> list;
	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		list.push_back(temp);
		// 왜냐면 처음 한 번에 Takahashi 가 먹고 끝내버림
		dp[temp] = temp;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < list.size(); j++) {
			if (list[j] <= i) {
				dp[i] = max(dp[i], i - dp[i - list[j]]);
			}
		}
	}

	cout << dp[N];
		
	return 0;
}