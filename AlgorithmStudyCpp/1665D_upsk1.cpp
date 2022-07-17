#include <bits/stdc++.h>
using namespace std;



int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		long long ans = 0;
		for (int i = 0; i < 30; i++) {
			long long a = (1LL << i) * 3LL - ans, b = (1LL << i) - ans;
			long long num;
			cout << "? " << a << ' ' << b << endl;
			cin >> num;
			if (num == (1LL << (i + 1)))ans += (1LL << i);
		}
		cout << "! " << ans << endl;

	}
}