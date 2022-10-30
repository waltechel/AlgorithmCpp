#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;

	cin >> s;

	char answer = ' ';
	for (char i = 'a'; i <= 'z'; i++) {
		int cnt = 0;
		for (int j = 0; j < s.length(); j++) {
			if (i == s[j]) {
				cnt++;
			}
		}
		if (cnt == 1) {
			answer = i;
			break;
		}
	}

	if (answer == ' ') {
		cout << "-1";
	} else {
		cout << answer;
	}


	return 0;
}