#include <bits/stdc++.h>
using namespace std;
vector<int> getPi(string p) {
	int m = p.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) j = pi[j - 1];
		if (p[i] == p[j])pi[i] = ++j;
	}
	return pi;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s1, s2;
	cin >> s1 >> s2;
	auto pi = getPi(s1 + s2);
	vector<int> ans;
	ans.push_back(s1.size() + s2.size());
	for (int i = pi[pi.size() - 1]; i > 0; i = pi[i - 1]) {
		if (i)ans.push_back(i);
	}
	for (int i = ans.size() - 1; i >= 0; i--)cout << ans[i] << ' ';
}
