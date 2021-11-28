#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
// P = A * 2^B + 1
// W^k != 1, 1 <= k < P - 1
// invW * W = 1 mod P
constexpr ll P = 998244353;
constexpr ll power(ll a, ll n) {
	ll res = 1;
	while(n) {
		if(n & 1) res = (res * a) % P;
		a = (a * a) % P;
		n >>= 1;
	}
	return res;
}
constexpr ll A = 119;
constexpr ll B = 23;
constexpr ll W = power(3, A);
constexpr ll invW = power(W, P - 2);
void ntt(vector<ll> &v, bool inv) {
	ll const n = (ll)v.size();
	for(ll i = 1, j = 0; i < n; i++) {
		ll bit = n >> 1;
		for(; j >= bit; bit >>= 1) j -= bit;
		j += bit;
		if(i < j) swap(v[i], v[j]);
	}

	for(ll i = 1; i < n; i <<= 1) {
		ll const x = power(inv ? invW : W, (P / i) >> 1);
		for(ll j = 0; j < n; j += (i << 1)) {
			ll y = 1;
			for(ll k = 0; k < i; k++) {
				ll const z = (v[i | j | k] * y) % P;
				v[i | j | k] = v[j | k] - z;
				if(v[i | j | k] < 0) v[i | j | k] += P;
				v[j | k] += z;
				if(v[j | k] >= P) v[j | k] -= P;
				y = (y * x) % P;
			}
		}
	}

	if(inv) {
		ll const j = power(n, P - 2);
		for(ll i = 0; i < n; i++) {
			v[i] = (v[i] * j) % P;
		}
	}
}
vector<ll> multiply(vector<ll> const &vs, vector<ll> const &vt) {
	assert(vs.size() == vt.size());
	vector<ll> res(vs.size());
	for(ll i = 0; i < vs.size(); i++) {
		res[i] = vs[i] * vt[i];
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c; cin >> c;
	cout << invW << ' ' << (W * invW) % P << '\n';
	string s, t;
	while(c--) {
		cin >> s >> t;
		ll n = 1;
		while(n < s.size() + t.size()) n <<= 1;
		vector<ll> vs, vt;
		vs.resize(n); vt.resize(n);
		for(ll i = 0; i < s.size(); i++) vs[i] = (s[i] == 'M');
		for(ll i = 0; i < t.size(); i++) vt[i] = (t[i] == 'M');
		ntt(vs, false); ntt(vt, false);
		vector<ll> res = multiply(vs, vt);
		ntt(res, true);
		ll cnt = 0;
		for(auto i : res) {
			cout << i << ' ';
		} cout << '\n';
		for(auto i = s.size() - 1; i != t.size(); i++) {
			cnt += (res[i] == 0);
		}
		cout << cnt << '\n';
	}
}