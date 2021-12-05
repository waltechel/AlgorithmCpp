#include <iostream>
#include <string>
using namespace std;
int f(string const &s, int n, int idx) {
	if(n == 3) {
		if((int)s[idx] == (int)s[idx + 1] && (int)s[idx + 1] == (int)s[idx + 2]) return 1;
		if((int)s[idx] + 1 == (int)s[idx + 1] && (int)s[idx + 1] + 1 == (int)s[idx + 2]) return 2;
		if((int)s[idx] == (int)s[idx + 1] + 1 && (int)s[idx + 1] == (int)s[idx + 2] + 1) return 2;
		if((int)s[idx] == (int)s[idx + 2]) return 4;
		if((int)s[idx] + (int)s[idx + 2] == 2 * (int)s[idx + 1]) return 5;
		return 10;
	}
	if(n == 4) {
		if((int)s[idx] == (int)s[idx + 1] && (int)s[idx + 1] == (int)s[idx + 2] && (int)s[idx + 2] == (int)s[idx + 3]) return 1;
		if((int)s[idx] + 1 == (int)s[idx + 1] && (int)s[idx + 1] + 1 == (int)s[idx + 2] && (int)s[idx + 2] + 1 == (int)s[idx + 3]) return 2;
		if((int)s[idx] == (int)s[idx + 1] + 1 && (int)s[idx + 1] == (int)s[idx + 2] + 1 && (int)s[idx + 2] == (int)s[idx + 3] + 1) return 2;
		if((int)s[idx] == (int)s[idx + 2] && (int)s[idx + 1] == (int)s[idx + 3]) return 4;
		if((int)s[idx] + (int)s[idx + 2] == 2 * (int)s[idx + 1] && (int)s[idx + 1] + (int)s[idx + 3] == 2 * (int)s[idx + 2]) return 5;
		return 10;
	}
	if((int)s[idx] == (int)s[idx + 1] && (int)s[idx + 1] == (int)s[idx + 2] && (int)s[idx + 2] == (int)s[idx + 3] && (int)s[idx + 3] == (int)s[idx + 4]) return 1;
	if((int)s[idx] + 1 == (int)s[idx + 1] && (int)s[idx + 1] + 1 == (int)s[idx + 2] && (int)s[idx + 2] + 1 == (int)s[idx + 3] && (int)s[idx + 3] + 1 == (int)s[idx + 4]) return 2;
	if((int)s[idx] == (int)s[idx + 1] + 1 && (int)s[idx + 1] == (int)s[idx + 2] + 1 && (int)s[idx + 2] == (int)s[idx + 3] + 1 && (int)s[idx + 3] == (int)s[idx + 4] + 1) return 2;
	if((int)s[idx] == (int)s[idx + 2] && (int)s[idx + 1] == (int)s[idx + 3] && (int)s[idx + 2] == (int)s[idx + 4]) return 4;
	if((int)s[idx] + (int)s[idx + 2] == 2 * (int)s[idx + 1] && (int)s[idx + 1] + (int)s[idx + 3] == 2 * (int)s[idx + 2] && (int)s[idx + 2] + (int)s[idx + 4] == 2 * (int)s[idx + 3]) return 5;
	return 10;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		auto a = new int[s.size() + 1]();
		for(int i = 3; i <= s.size(); i++) {
			a[i] = a[i - 3] + f(s, 3, i - 3);
			if(i > 3) {
				auto const x = a[i - 4] + f(s, 4, i - 4);
				if(a[i] > x) a[i] = x;
			}
			if(i > 4) {
				auto const x = a[i - 5] + f(s, 5, i - 5);
				if(a[i] > x) a[i] = x;
			}
		}
		cout << a[s.size()] << '\n';
		delete[] a;
	}
}