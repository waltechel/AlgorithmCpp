#include <bits/stdc++.h>
using namespace std;

int a[501], d[501];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			d[i] = 1;
		}
		int ans = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[i] > a[j]) {
					d[i] = max(d[i], d[j] + 1);
				}
			}
			ans = max(ans, d[i]);
		}
		cout << ans << '\n';
	}
}