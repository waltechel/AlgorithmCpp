#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		auto a = new int*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new int[i + 1];
			for(int j = 0; j <= i; j++) cin >> a[i][j];
		}
		for(int i = n - 1; i > 0; i--) {
			for(int j = 0; j < i; j++) {
				a[i - 1][j] += max(a[i][j], a[i][j + 1]);
			}
		}
		cout << a[0][0] << '\n';
		for(int i = 0; i < n; i++) delete[] a[i];
		delete[] a;
	}
}