#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, k, cnt = 0, ans1, ans2, size;
		cin >> n >> k;
		size = n - 1;
		for (int i = 2; i <= n; i++)q.push(i);
		while (true) {
			if (size == 2)break;
			cnt++;
			if (cnt % k == 0) {
				q.pop();
				size--;
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
		ans1 = q.front(); q.pop();
		ans2 = q.front(); q.pop();
		cout << min(ans1, ans2) << ' ' << max(ans1, ans2) << '\n';
	}

}