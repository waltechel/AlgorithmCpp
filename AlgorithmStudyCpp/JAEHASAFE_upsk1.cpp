#include <bits/stdc++.h>
using namespace std;
vector<int> getPi(string p) {
	int m = p.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])j = pi[j - 1];
		if (p[i] == p[j])pi[i] = ++j;
	}
	return pi;
}
int shifts(string s, string p) {
	s += s;
	int n = s.size(), m = p.size(), j = 0;
	vector<int> pi = getPi(p);
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])j = pi[j - 1];
		if (s[i] == p[j]) {
			j++;
			if (j == m)return i - m + 1;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, ans = 0;
		string s;
		cin >> n >> s;
		for (int i = 0; i < n; i++) {
			string next;
			cin >> next;
			if (i % 2) ans += shifts(s, next);
			else ans += shifts(next, s);
			s = next;
		}
		cout << ans << '\n';
	}
}