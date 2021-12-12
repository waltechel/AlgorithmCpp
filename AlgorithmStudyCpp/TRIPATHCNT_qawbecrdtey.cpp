#include <iostream>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		auto a = new pair<int, int>*[n];
		for(int i = 0; i < n; i++) {
			a[i] = new pair<int, int>[i + 1];
			for(int j = 0; j <= i; j++) a[i][j].first = 1, cin >> a[i][j].second;
		}
		for(int i = n - 1; i > 0; i--) {
			for(int j = 0; j < i; j++) {
				if(a[i][j].second == a[i][j + 1].second) {
					a[i - 1][j].first = a[i][j].first + a[i][j + 1].first;
					a[i - 1][j].second += a[i][j].second;
				}
				else if(a[i][j].second > a[i][j + 1].second) {
					a[i - 1][j].first = a[i][j].first;
					a[i - 1][j].second += a[i][j].second;
				}
				else {
					a[i - 1][j].first = a[i][j + 1].first;
					a[i - 1][j].second += a[i][j + 1].second;
				}
			}
		}
		cout << a[0][0].first << '\n';
		for(int i = 0; i < n; i++) delete[] a[i];
		delete[] a;
	}
}