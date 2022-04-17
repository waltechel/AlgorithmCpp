#include <iostream>
using namespace std;
int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		auto a = new int[n];
		auto b = new int[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int g = a[0];
		for(int i = 1; i < n; i++) g = gcd(g, a[i]);
		for(int i = 0; i < n; i++) a[i] /= g;
		int m = g;
		for(int i = 0; i < n; i++) {
			cin >> b[i];
			m = max((b[i] + a[i] - 1) / a[i], m);
		}
		for(int i = 0; i < n; i++) {
			cout << a[i] * m - b[i] << ' ';
		} cout << '\n';
		delete[] a;
		delete[] b;
	}
}