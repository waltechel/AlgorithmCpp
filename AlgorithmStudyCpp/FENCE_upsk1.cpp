#include <bits/stdc++.h>
using namespace std;
stack<int> st, idx;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			while (!st.empty()) {
				if (st.top() < t)break;
				else {
					int w, h = st.top();
					st.pop(); idx.pop();
					if (st.empty()) w = i;
					else w = i - idx.top() - 1;
					ans = max(ans, w * h);
				}
			}
			st.push(t);
			idx.push(i);
		}
		while (!st.empty()) {
			int w, h = st.top();
			st.pop(); idx.pop();
			if (st.empty()) w = n;
			else w = n - idx.top() - 1;
			ans = max(ans, w * h);
		}
		cout << ans << '\n';
	}

}