#include <bits/stdc++.h>
using namespace std;
int a[101], b[101];
bool check[101];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)check[i] = false;
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++)cin >> b[i];
		sort(a, a + n);
		sort(b, b + n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (check[j])continue;
				if (b[i] >= a[j]) {
					ans++;
					check[j] = true;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
}