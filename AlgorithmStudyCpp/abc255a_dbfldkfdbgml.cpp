#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_set>
#include <set>

using namespace std;

int dp[3][3];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int R, C;
	cin >> R >> C;
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= 2; j++) {
			cin >> dp[i][j];
		}
	}
	
	cout << dp[R][C];
	
	return 0;
}