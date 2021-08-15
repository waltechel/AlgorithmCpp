#include <bits/stdc++.h>
using namespace std;
stack<char> st;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (st.empty())st.push(s[i]);
			else {
				if (s[i] == '(' || s[i] == '[' || s[i] == '{')st.push(s[i]);
				else {
					if (st.empty()) {
						st.push(s[i]);
						break;
					}
					else {
						if (s[i] == ')') {
							if (st.top() == '(') st.pop();
							else {
								st.push(s[i]);
								break;
							}
						}
						else if (s[i] == ']') {
							if (st.top() == '[')st.pop();
							else {
								st.push(s[i]);
								break;
							}
						}
						else {
							if (st.top() == '{')st.pop();
							else {
								st.push(s[i]);
								break;
							}
						}
					}
				}
			}
		}
		if (st.empty())cout << "YES\n";
		else cout << "NO\n";
		while (!st.empty())st.pop();
	}

}