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

	int N, K;
	cin >> N >> K;

	vector<int> list;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		list.push_back(temp);
	}

	int* dp = new int[10001];
	for (int i = 0; i <= 10000; i++) {
		dp[i] = 1 << 30;
	}
	dp[0] = 0;
	for (int i = 0; i <= 10000; i++) {
		for (int j = 0; j < list.size(); j++) {
			int next = list[j];
			if (i + next <= 10000) {
				dp[i + next] = min(dp[i + next], dp[i] + 1);
			}
		}
	}

	if (dp[K] == 1 << 30) {
		cout << "-1";
	} else {
		cout << dp[K] << "";
	}


	return 0;
}