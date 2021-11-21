#include <bits/stdc++.h>
using namespace std;
string Reverse(string::iterator& it) {
	char head = *it;
	it++;
	if (head == 'b' || head == 'w')return string(1, head);
	string s1 = Reverse(it);
	string s2 = Reverse(it);
	string s3 = Reverse(it);
	string s4 = Reverse(it);
	return "x" + s3 + s4 + s1 + s2;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		auto it = s.begin();
		cout << Reverse(it) << '\n';
	}
}