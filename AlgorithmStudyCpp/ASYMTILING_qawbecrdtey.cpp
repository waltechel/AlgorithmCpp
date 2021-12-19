#include <stdio.h>
using ll = long long;
constexpr ll M = 1000000007;
int main() {
	int t; scanf("%d", &t);
	ll f[101] = { 1, 1 };
	for(int i = 2; i <= 100; i++) f[i] = (f[i - 1] + f[i - 2]) % M;
	while(t--) {
		ll n; scanf("%lld", &n);
		auto const x = ((f[n] - f[n / 2]) % M + M) % M;
		if(n & 1) printf("%lld\n", x);
		else printf("%lld\n", ((x - f[n / 2 - 1]) % M + M) % M);
	}
}