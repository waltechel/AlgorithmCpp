#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

bool list[2006];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int N;
	cin >> N;

	while (true) {
		for (int i = 1; i <= 2 * N + 1; i++) {
			if (list[i] == false) {
				list[i] = true;
				// After each output, you must flush Standard Output. Otherwise, you may get .
				cout << i << endl;
				// cout.flush();
				break;
			}
		}

		int next;
		cin >> next;
		if (next == 0) {
			break;
		}
		list[next] = true;
	}

	return 0;
}