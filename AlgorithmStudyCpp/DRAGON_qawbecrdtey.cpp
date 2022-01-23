#include <iostream>
using namespace std;
using ll = long long;
ll power(int a, int n) {
	if(!n) return 1;
	if(n == 1) return a;
	ll const r = power(a, n >> 1);
	return r * r * power(a, n & 1);
}
inline ll calc(int n) {
	ll t = power(2, n);
	return ((t << 1) | t) - 2;
}
char f(char const s[], int n, ll i, ll cur) {
	ll const c = calc(n);
	if(!n) {
		if(!i) return s[cur];
		else return f(s, 0, i - 1, cur + 1);
	}
	if(s[cur] == 'X') {
		if(i >= c) return f(s, n, i - c, cur + 1);
		else return f("X+YF", n - 1, i, 0);
	}
	else if(s[cur] == 'Y') {
		if(i >= c) return f(s, n, i - c, cur + 1);
		else return f("FX-Y", n - 1, i, 0);
	} else {
		if(!i) return s[cur];
		else return f(s, n, i - 1, cur + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t, n, p, l;
	cin >> t;
	while(t--) {
		cin >> n >> p >> l;
		for(int i = p - 1; i < p + l - 1; i++) {
			cout << f("FX", n, i, 0);
		} cout << '\n';
	}
}