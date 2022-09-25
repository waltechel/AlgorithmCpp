#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

long long dp[11][2];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N, X, Y;
	cin >> N >> X >> Y;

	dp[N][0] = 1;
	for(int i = N ; i >= 2 ; i--){
		dp[i - 1][0] += dp[i][0];
		dp[i][1] += (dp[i][0] * X);
		dp[i][0] = 0;
		dp[i - 1][0] += dp[i][1];
		dp[i - 1][1] += (dp[i][1] * Y);
		dp[i][1] = 0;
	}

	cout << dp[1][1];

	return 0;
}