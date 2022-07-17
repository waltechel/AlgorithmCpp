#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> p[i].second >> p[i].first;
	sort(p, p + n);
	int start = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (p[i].second >= start) {
			ans++;
			start = p[i].first;
		}
	}
	cout << ans << '\n';

}