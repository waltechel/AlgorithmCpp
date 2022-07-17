#include <bits/stdc++.h>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			long long t;
			cin >> t;
			pq.push(t);
		}
		while (true) {
			long long a = pq.top();
			pq.pop();
			if (pq.empty())break;
			long long b = pq.top();
			pq.pop();
			ans += a + b;
			pq.push(a + b);
		}
		cout << ans << '\n';
	}

}