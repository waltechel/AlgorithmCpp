#include <iostream>
#include <string>
using namespace std;
string flip(string const &s, unsigned long idx) {
	if(s[idx] != 'x') return string() + s[idx];
	string res = "x";
	string s1 = flip(s, ++idx);
	string s2 = flip(s, idx += s1.size());
	string s3 = flip(s, idx += s2.size());
	string s4 = flip(s, idx += s3.size());
	res += s3 + s4 + s1 + s2;
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	string s;
	while(t--) {
		cin >> s;
		cout << flip(s, 0) << '\n';
	}
}