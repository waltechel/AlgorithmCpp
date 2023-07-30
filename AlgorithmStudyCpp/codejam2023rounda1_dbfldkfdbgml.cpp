#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>
#include <unordered_set>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(0);

	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		char encoder[26];
		for (int j = 0; j < 26; j++) {
			cin >> encoder[j];
		}

		unordered_set<string> inputs;
		bool flag = false;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string line;
			cin >> line;
			for (int j = 0; j < line.length(); j++) {
				line[j] = encoder[line[j] - 'A'];
			}
			if (inputs.find(line) == inputs.end()) {
				inputs.insert(line);
			} else {
				flag = true;
			}
		}
		if (flag) {
			cout << "Case #" << test << ": YES\n";
		} else {
			cout << "Case #" << test << ": NO\n";
		}

	}
	
	return 0;
}