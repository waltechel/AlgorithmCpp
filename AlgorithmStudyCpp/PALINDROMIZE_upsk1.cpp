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
int kmp(string s, string p) {
	int n = s.size(), m = p.size(), j = 0;
	auto pi = getPi(p);
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])j = pi[j - 1];
		if (s[i] == p[j]) {
			j++;
			if (i == (n - 1))return j;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string s1, s2 = "";
		cin >> s1;
		for (int i = s1.size() - 1; i >= 0; i--)s2 += s1[i];
		cout << (int)s1.size() * 2 - kmp(s1, s2) << '\n';
	}
}