#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>

/*
	혹시 이거 리팩토링 어떻게 하실 거 같으신가요?
*/

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	string S;
	cin >> S;
	
	bool uppercase = false;
	for (int i = 0; i < S.size(); i++) {
		if ('A' <= S[i] && S[i] <= 'Z') {
			uppercase = true;
		}
	}

	bool lowercase = false;
	for (int i = 0; i < S.size(); i++) {
		if ('a' <= S[i] && S[i] <= 'z') {
			lowercase = true;
		}
	}

	bool distinct = true;
	for (int i = 0; i < S.size(); i++) {
		for (int j = i + 1; j < S.size(); j++) {
			if (S[i] == S[j]) {
				distinct = false;
			}
		}
	}

	if (uppercase && lowercase && distinct) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}