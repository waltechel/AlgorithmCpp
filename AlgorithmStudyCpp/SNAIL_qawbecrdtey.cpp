#include <algorithm>
#include <cstdio>
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		long double a[2001] = { 1.0 };
		long double ans = 0;
		int n, m;
		scanf("%d%d", &n, &m);
		while(m--) {
			long double b[2001] = {};
			for(int i = 0; i < n; i++) {
				if(i == n - 1) ans += a[n - 1];
				else if(i == n - 2) ans += a[n - 2] * 0.75, b[n - 1] += a[n - 2] * 0.25;
				else b[i + 2] += a[i] * 0.75, b[i + 1] += a[i] * 0.25;
			}
			std::copy(b, b + 2001, a);
		}
		printf("%.15Lf\n", ans);
	}
}