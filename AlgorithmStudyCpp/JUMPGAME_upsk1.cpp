#include <bits/stdc++.h>
using namespace std;
int a[101][101];
bool c[101][101];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				c[i][j] = false;
			}
		}
		c[1][1] = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (c[i][j]) {
					if (j + a[i][j] <= n) {
						c[i][j + a[i][j]] = true;
					}
					if (i + a[i][j] <= n) {
						c[i + a[i][j]][j] = true;
					}
				}
			}
		}
		if (c[n][n])cout << "YES\n";
		else cout << "NO\n";
	}
}