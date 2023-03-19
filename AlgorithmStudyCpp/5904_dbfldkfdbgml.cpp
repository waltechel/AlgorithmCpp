#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <string>

using namespace std;
vector<long long> S;

void dfs(int n) {
	if (n == 1) {
		cout << "m";
		return;
	} else if (n == 2) {
		cout << "o";
		return;
	} else if (n == 3) {
		cout << "o";
		return;
	}

	for (int i = 0; i < 30; i++) {
		// 처음 이 수를 커버하는 수가 나타났을 때
		if (S[i] >= n) {
			// 이 수의 위치가 새로운 moooo 에서 나타났을 때
			if (n <= S[i - 1] + i + 3) {
				if (n == S[i - 1] + 1) {
					cout << "m";
				} else {
					cout << "o";
				}
				return;
			} else {
				dfs(n - S[i - 1] - i - 3);
			}
			break;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	S.push_back(3);
	for (int i = 1; i < 30; i++) {
		S.push_back(S[i - 1] + i + 3 + S[i - 1]);
	}

	int N;
	cin >> N;
	dfs(N);

	return 0;
}