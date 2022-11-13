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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);


	double* dp = new double[101];
	dp[1] = 3.5;
	for (int i = 2; i <= 100; i++) {
		dp[i] = max(dp[i - 1], 1.0) / 6.0
			+ max(dp[i - 1], 2.0) / 6.0
			+ max(dp[i - 1], 3.0) / 6.0
			+ max(dp[i - 1], 4.0) / 6.0
			+ max(dp[i - 1], 5.0) / 6.0
			+ max(dp[i - 1], 6.0) / 6.0;
	}

	int N;
	cin >> N;
	cout << dp[N];

	return 0;
}

