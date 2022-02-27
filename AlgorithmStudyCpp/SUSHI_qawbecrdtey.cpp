#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n, m; cin >> n >> m; m /= 100;
		int *a[2];
		a[0] = new int[m + 1]();
		a[1] = new int[m + 1];
		while(n--) {
			int x, y; cin >> x >> y; x /= 100;
			for(int j = 0; j <= m; j++) {
				a[1][j] = a[0][j];
				if(j >= x && a[1][j] < a[1][j - x] + y) a[1][j] = a[1][j - x] + y;
			}
			swap(a[0], a[1]);
		}
		cout << a[0][m] << '\n';
		delete[] a[0]; delete[] a[1];
	}
}