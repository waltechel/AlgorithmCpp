#include <bits/stdc++.h>
using namespace std;
long long all[101], d[101];
const long long mod = 1000000007;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	all[1] = 1; all[2] = 2;
	for (int i = 3; i <= 100; i++) {
		all[i] = (all[i - 1] + all[i - 2]) % mod;
		if (i % 2)d[i] = all[i] - all[i / 2];
		else d[i] = all[i] - all[i / 2] - all[i / 2 - 1];
		while (d[i] < 0)d[i] += mod;
	}
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
}