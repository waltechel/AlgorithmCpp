#include <bits/stdc++.h>
using namespace std;
struct RNG {
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};
long long cntRange(int k, int n) {
	RNG rng;
	queue<int> q;
	int ret = 0, rangeSum = 0;
	for (int i = 0; i < n; i++) {
		int newSignal = rng.next();
		rangeSum += newSignal;
		q.push(newSignal);
		while (rangeSum > k) {
			rangeSum -= q.front();
			q.pop();
		}
		if (rangeSum == k)ret++;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int k, n;
		cin >> k >> n;
		cout << cntRange(k, n) << '\n';
	}
}