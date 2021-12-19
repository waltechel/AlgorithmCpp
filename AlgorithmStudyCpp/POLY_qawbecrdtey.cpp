#include <stdio.h>
using ll = long long;
constexpr ll M = 10000000;
ll dp(ll arr[101][101], int len, int left) {
	if(arr[len][left] != -1) return arr[len][left];
	if(!left) return arr[len][left] = 1;
	ll res = 0;
	for(int i = 1; i <= left; i++) {
		res += (len + i - 1) * dp(arr, i, left - i);
	} res %= M;
	return arr[len][left] = res;
}
int main() {
	int t, n;
	ll arr[101][101];
	for(auto &i : arr) for(auto &j : i) j = -1;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		ll res = 0;
		for(int i = 1; i <= n; i++) res += dp(arr, i, n - i);
		res %= M;
		printf("%lld\n", res);
	}
}