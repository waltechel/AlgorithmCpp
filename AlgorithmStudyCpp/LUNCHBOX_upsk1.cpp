#include <bits/stdc++.h>
using namespace std;
struct A {
	int m, e;
	bool operator<(const A& p)const {
		return e > p.e;
	}
};
A a[10001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)cin >> a[i].m;
		for (int i = 0; i < n; i++)cin >> a[i].e;
		sort(a, a + n);
		int ans = 0, start = 0;
		for (int i = 0; i < n; i++) {
			start += a[i].m;
			ans = max(ans, start + a[i].e);
		}
		cout << ans << '\n';
	}
}