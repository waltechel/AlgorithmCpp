#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	bool ischecked[10];
	for (int i = 0; i < 10; i++) {
		ischecked[i] = false;
	}

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		int index = (int) (s[i] - '0');
		ischecked[index] = true;
	}

	for (int i = 0; i < 10; i++) {
		if (!ischecked[i]) {
			cout << i;
		}
	}

	

	return 0;
}