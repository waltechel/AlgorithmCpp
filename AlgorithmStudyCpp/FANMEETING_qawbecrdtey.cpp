#include <algorithm>
#include <complex>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using cld = complex<long double>;
template<bool inv>
void fft(vector<cld> &a) {
	auto const n = a.size();
	int j = 0;
	vector<cld> roots(n >> 1);
	for(int i = 1; i < n; i++) {
		int bit = (n >> 1);
		while(j >= bit) {
			j -= bit;
			bit >>= 1;
		} j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	cld w(cos(M_PIl / (n >> 1)), sin(M_PIl / (n >> 1))), ww(1);
	if(inv) w = conj(w);
	for(int i = 0; i < (n >> 1); i++) {
		roots[i] = ww;
		ww *= w;
	}
	int step = n >> 1;
	for(int i = 1; i < n; i <<= 1) {
		for(j = 0; j < n; j += i) {
			int stepk = 0;
			for(int k = 0; k < i; k++) {
				cld const u = a[j + k], v = a[j + k + i] * roots[stepk];
				a[j + k] = u + v;
				a[j + k + i] = u - v;
				stepk += step;
			}
		}
		step >>= 1;
	}
	if(inv) {
		for(auto &now : a) now /= n;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		string s1, s2; cin >> s1 >> s2;
		int N = 1; while(N < s1.length() + s2.length()) N <<= 1;
		reverse(s2.begin(), s2.end());
		vector<cld> a(N), b(N);
		for(int i = 0; i < s1.size(); i++) a[i] = (s1[i] == 'M');
		for(int i = 0; i < s2.size(); i++) b[i] = (s2[i] == 'M');
		fft<false>(a); fft<false>(b);
		for(int i = 0; i < N; i++) a[i] *= b[i];
		fft<true>(a);
		int res = 0;
		for(int i = min(s1.size(), s2.size()) - 1; i < max(s1.size(), s2.size()); i++) {
			//cout << a[i] << '\n';
			res += !(long long)(round(a[i].real()));
		} cout << res << '\n';
	}
}