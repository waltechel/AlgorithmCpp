#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string members;
	string fans;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {

		cin >> members;
		cin >> fans;

		bool* A = new bool[members.length()];
		for (int i = 0; i < (int)members.length(); i++) {
			A[i] = members[i] == 'M';
		}
		bool* B = new bool[fans.length()];
		for (int i = 0; i < (int)fans.length(); i++) {
			B[i] = fans[fans.length() - 1 - i] == 'M';
		}

		int answer = 0;
		bool flag = false;
		for (int i = 0; i < (int) members.length() + (int) fans.length() - 1; i++) {
			if (i < (int) members.length() - 1) {
				continue;
			}
			bool check = true;
			for (int j = 0; j <(int) members.length(); j++) {
				int k = i - j;
				if (k >= (int) fans.length()) {
					flag = true;
					break;
				}
				// 남자 남자가 만났다
				if (A[j] & B[k]) {
					check = false;
					break;
				}
			}
			if (flag) {
				break;
			}
			if (check) {
				answer++;
			}

		}
		cout << answer << "\n";

	}

	return 0;
}