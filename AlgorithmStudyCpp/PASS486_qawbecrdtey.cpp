#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	auto a = new int[10000001]();
	for(int i = 1; i <= 10000000; i++) {
		for(int j = i; j <= 10000000; j += i) a[j]++;
	}
	int t; cin >> t; while(t--) {
		int n, lo, hi; cin >> n >> lo >> hi;
		int cnt = 0;
		for(int i = lo; i <= hi; i++) cnt += (a[i] == n);
		cout << cnt << '\n';
	}
	delete[] a;
}