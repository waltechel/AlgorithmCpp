#include <bits/stdc++.h>
using namespace std;
const long long mod = 20090711;
priority_queue<long long> leftQ, leftReset;
priority_queue<long long, vector<long long>, greater<long long>> rightQ, rightReset;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		long long start = 1983, n, a, b, sum = 1983, mid = 1983, lsize = 0, rsize = 0;
		cin >> n >> a >> b;
		for (int i = 1; i < n; i++) {
			start = (start * a + b) % mod;
			if (start < mid) {
				lsize++;
				leftQ.push(start);
			}
			else {
				rsize++;
				rightQ.push(start);
			}
			if (rsize - lsize > 1) {
				lsize++;
				leftQ.push(mid);
				mid = rightQ.top();
				rsize--;
				rightQ.pop();
			}
			if (lsize > rsize) {
				rsize++;
				rightQ.push(mid);
				mid = leftQ.top();
				lsize--;
				leftQ.pop();
			}
			sum += mid;
			sum %= mod;
		}
		leftQ = leftReset;
		rightQ = rightReset;
		cout << sum << '\n';
	}
}