#include <iostream>
using namespace std;
using ld = long double;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cout << fixed;
	cout.precision(10);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;

		// input
		auto arr = new ld*[n];
		auto dp = new ld*[n];
		for(int i = 0; i < n; i++) {
			arr[i] = new ld[n];
			dp[i] = new ld[1 << n];
			dp[i][(1 << n) - 1] = 0;
			for(int j = 0; j < n; j++) cin >> arr[i][j];
		}

		for(int i = (1 << n) - 2; i >= 0; i--) { // cities visited = 1
			for(int j = 0; j < n; j++) { // current city
				if(i & (1 << j)) continue;
				int const next = (i | (1 << j));
				if(next == (1 << n) - 1) {
					dp[j][i] = 0;
					continue;
				}
				dp[j][i] = 21225.0;
				for(int k = 0; k < n; k++) {
					if(next & (1 << k)) continue;
					ld const x = dp[k][next] + arr[j][k];
					if(dp[j][i] > x) dp[j][i] = x;
				}
			}
		}

		ld min = 21225.0;
		for(int i = 0; i < n; i++) {
			if(min > dp[i][0]) min = dp[i][0];
		} cout << min << '\n';

		for(int i = 0; i < n; i++) delete[] arr[i];
		delete[] arr;
	}
}