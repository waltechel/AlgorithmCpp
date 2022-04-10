#include <cmath>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout.precision(15);
	cout << fixed;
	int t; cin >> t; while(t--) {
		long double n, p; int m; cin >> n >> m >> p;
		long double const x = powl((100 + p / 12) / 100, m);
		long double const res = n * x / (x - 1) * ((100 + p / 12) / 100 - 1);
		cout << res << '\n';
	}
}