#include <stdio.h>
int main() {
	int t, n, a, b;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		if(n < 4) { printf("%d\n", n); continue; }
		a = 2, b = 3;
		for(int i = 3; i < n; i++) {
			int x = a; a = b; b = (b + x) % 1000000007;
		} printf("%d\n", b);
	}
}