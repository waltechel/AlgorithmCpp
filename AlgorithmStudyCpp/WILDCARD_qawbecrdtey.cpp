#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int dp(string const &s, string const &t, int **arr, int sidx, int tidx) {
	if(sidx > s.size() || tidx > t.size()) return 0;
	if(arr[sidx][tidx] != -1) return arr[sidx][tidx];
	if(sidx == s.size() && tidx == t.size()) return arr[sidx][tidx] = 1;
	if(s[sidx] == '*')
		return arr[sidx][tidx] = (dp(s, t, arr, sidx, tidx + 1) || dp(s, t, arr, sidx + 1, tidx));
	if(sidx == s.size() || tidx == t.size()) return 0;
	if(s[sidx] == '?') return arr[sidx][tidx] = dp(s, t, arr, sidx + 1, tidx + 1);
	return arr[sidx][tidx] = (s[sidx] == t[tidx] && dp(s, t, arr, sidx + 1, tidx + 1));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c; cin >> c;
	while(c--) {
		string s, t; cin >> s;
		int n; cin >> n;
		vector<string> v;
		auto arr = new int*[s.size() + 1];
		while(n--) {
			cin >> t;
			for(int i = 0; i <= s.size(); i++) {
				arr[i] = new int[t.size() + 1];
				fill(arr[i], arr[i] + t.size() + 1, -1);
			}
			if(dp(s, t, arr, 0, 0)) v.emplace_back(move(t));
			for(int i = 0; i <= s.size(); i++) delete[] arr[i];
		}
		sort(v.begin(), v.end());
		for(auto const &now : v) cout << now << '\n';
		delete[] arr;
	}
}