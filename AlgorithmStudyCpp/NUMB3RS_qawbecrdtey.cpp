#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.precision(10);
	cout << fixed;
	int c; cin >> c;
	while(c--) {
		int n, d, p, t;
		cin >> n >> d >> p;
		auto v = new vector<int>[n];
		for(int i = 0; i < n; i++) {
			int x;
			for(int j = 0; j < n; j++) {
				cin >> x;
				if(x) v[i].push_back(j);
			}
		}
		auto cur = new long double[n]();
		auto next = new long double[n];
		cur[p] = 1.0;
		while(d--) {
			fill(next, next + n, 0.0);
			for(int i = 0; i < n; i++) {
				auto x = cur[i] / v[i].size();
				for(int now : v[i]) {
					next[now] += x;
				}
			}
			copy(next, next + n, cur);
		}
		cin >> t;
		while(t--) {
			int x; cin >> x;
			cout << cur[x] << ' ';
		} cout << '\n';
		delete[] cur;
		delete[] next;
		delete[] v;
	}
}