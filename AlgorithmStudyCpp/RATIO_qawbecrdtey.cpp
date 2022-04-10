#include <iostream>
using namespace std;
using ll = unsigned long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		ll n, m; cin >> n >> m;
		ll const z = (100 * m) / n;
		if(99 * n <= 100 * m) {
			cout << "-1" << '\n';
			continue;
		} cout << ((z + 1) * n - 100 * m) / (99 - z) + (((z + 1) * n - 100 * m) % (99 - z) != 0) << '\n';
	}
}